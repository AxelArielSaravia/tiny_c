#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char const* argv[argc]) {
    if (argc < 2) {
        fprintf(stderr, "Specify a filename\n");
        exit(1);
    }

    char const* filename = argv[1];

    struct stat fs = {0};
    printf("Info from file \"%s\"\n", filename);

    int r = stat(filename, &fs);
    if (r == -1) {
        fprintf(stderr, "Error reading \"%s\"\n", filename);
        exit(1);
    }

    printf("Type and mode: %u\n", fs.st_mode);
    if (S_ISREG(fs.st_mode)) {
        printf("\"%s\" is a regular file\n", filename);
    } else if (S_ISDIR(fs.st_mode)) {
        printf("\"%s\" is a directory\n", filename);
    } else {
        printf("\"%s\" is some other type of file\n", filename);
    }

    return 0;
}
