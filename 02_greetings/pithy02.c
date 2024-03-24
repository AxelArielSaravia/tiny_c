#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 256

int main(int argc, char* argv[argc]) {
    char const*const filename = "pithy.txt";
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(1);
    }
    char* r;
    char* entry;
    char buffer[BSIZE];
    int items = 0;
    while (!feof(fp)) {
        r = fgets(buffer, BSIZE, fp);
        if (!r) {
            break;
        }
        entry = malloc(sizeof(char) * (strlen(buffer) + 1));
        if (!entry) {
            fprintf(stderr, "Unable to allocate memory\n");
            exit(1);
        }
        strcpy(entry, buffer);
        printf("%d: %s", items, entry);
        items += 1;
    }
    fclose(fp);
    return 0;
}
