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

    char const* list_base[100];

    char* r;
    char buffer[BSIZE];
    char* entry;
    int items = 0;
    while (!feof(fp) && items < 100) {
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
        list_base[items] = entry;
        items += 1;
    }
    fclose(fp);

    for (int i = 0; i < items; i += 1) {
        printf("%d: %s", i, list_base[i]);
    }
}
