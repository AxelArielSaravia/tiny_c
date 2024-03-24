#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <glob.h>

#ifdef PATH_MAX
    #undef PATH_MAX
#endif
#define PATH_MAX 256

int count = 0;

void find(char const* dirpath, char const* parentpath, char const* match) {
    DIR* dp = opendir(dirpath);
    if (!dp) {
        fprintf(stderr, "Unable to read directory \"%s\"\n", dirpath);
        exit(1);
    }

    glob_t gstruct = {0};
    int g = glob(match, GLOB_ERR, (void*)0, &gstruct);
    if (g == 0) {
        char** found = gstruct.gl_pathv;
        int i = 0;
        while (found[i]) {
            printf("%s/%s\n", dirpath, found[i]);
            i += 1;
            count += 1;
        }
    }

    char subdirpath[BUFSIZ];
    struct stat fs = {0};
    struct dirent* entry = readdir(dp);
    while (entry) {
        stat(entry->d_name, &fs);
        if (S_ISDIR(fs.st_mode) && entry->d_name[0] != '.') {
            if (chdir(entry->d_name) == -1) {
                fprintf(stderr, "Unable to change to %s\n", entry->d_name);
                exit(1);
            }
            getcwd(subdirpath, BUFSIZ);
            find(subdirpath, dirpath, match);
        }
        entry = readdir(dp);
    }
    closedir(dp);

    if (!parentpath) {
        return;
    }
    if (chdir(parentpath) == -1) {
        fprintf(stderr, "Parent directory lost\n");
        exit(1);
    }
}

int main() {
    printf("Filename or Wildcard: ");
    char filename[PATH_MAX];
    char current[PATH_MAX];
    char* r = fgets(filename, PATH_MAX, stdin);
    if (!r) {
        exit(1);
    }
    int i = 0;
    while (r[i] != '\0' && r[i] != '\n') {
        i +=1;
    }
    r[i] = '\0';

    getcwd(current, PATH_MAX);
    if (chdir(current) == -1) {
        fprintf(stderr, "Unable to access directory \"%s\"\n", current);
        exit(1);
    }

    printf("Searching for \"%s\"\n", filename);
    find(current, (void*)0, filename);

    printf(" Found %d match", count);
    if (count != 1) {
        printf("es");
    }
    putchar('\n');

    return 0;
}
