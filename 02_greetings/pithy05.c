#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 256

int main(int argc, char* argv[argc]) {
    char const*const filename = "pithy.txt";
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(1);
    }

    char const** list_base = malloc(sizeof(char*) * 100);

    char* r;
    char buffer[BSIZE];
    char* entry;
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
        if (items%100 == 0) {
            list_base = realloc(list_base, sizeof(char*) * (items + 100));
            if (!list_base) {
                fprintf(stderr, "Unable to reallocate memory\n");
                exit(1);
            }
        }
        list_base[items] = entry;
        items += 1;
    }
    fclose(fp);

    srand((unsigned)time(0));
    int saying = rand() % (items - 1);
    printf("%d: %s", saying, list_base[saying]);
    return 0;
}
