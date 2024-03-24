#include <stdio.h>
#include <stdlib.h>

#define BSIZE 256

int main(int argc, char* argv[argc]) {
    char const*const filename = "pithy.txt";
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(1);
    }
    char* r;
    char buffer[BSIZE];
    while (!feof(fp)) {
        r = fgets(buffer, BSIZE, fp);
        if (!r) {
            break;
        }
        printf("%s", buffer);
    }
    fclose(fp);
    return 0;
}
