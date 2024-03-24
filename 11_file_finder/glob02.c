#include <stdio.h>
#include <stdlib.h>
#include <glob.h>

#ifndef PATH_MAX
    #define PATH_MAX 256
#endif

int main() {
    printf("Filename or wildcard: ");

    char filename[PATH_MAX];
    char* r = fgets(filename, PATH_MAX, stdin);
    if (!r) {
        exit(1);
    }

    int i = 0;
    while (r[i] != '\0' && r[i] != '\n') {
        i +=1;
    }
    r[i] = '\0';

    glob_t gstruct = {0};
    int g = glob(filename, GLOB_ERR, (void*)0, &gstruct);
    if (g != 0) {
        if (g == GLOB_NOMATCH) {
            fprintf(stderr, "No matches for \"%s\"\n", filename);
        } else {
            fprintf(stderr, "Some kinda glob error\n");
        }
        exit(1);
    }

    printf("Found %zu filename matches\n", gstruct.gl_pathc);
    char** found = gstruct.gl_pathv;
    i = 0;
    while (found[i]) {
        printf("%s\n", found[i]);
        i += 1;
    }

    return 0;
}
