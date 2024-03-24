#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


void permissions_out(mode_t stm) {
    char const* perm[2] = {
        "---",
        "rwx"
    };
    putchar(perm[(stm & S_IRUSR) == S_IRUSR][0]);
    putchar(perm[(stm & S_IWUSR) == S_IWUSR][1]);
    putchar(perm[(stm & S_IXUSR) == S_IXUSR][2]);
    putchar(' ');
    putchar(perm[(stm & S_IRGRP) == S_IRGRP][0]);
    putchar(perm[(stm & S_IWGRP) == S_IWGRP][1]);
    putchar(perm[(stm & S_IXGRP) == S_IXGRP][2]);
    putchar(' ');
    putchar(perm[(stm & S_IROTH) == S_IROTH][0]);
    putchar(perm[(stm & S_IWOTH) == S_IWOTH][1]);
    putchar(perm[(stm & S_IXOTH) == S_IXOTH][2]);
    putchar(' ');
}

int main(int argc, char const* argv[argc]) {
    if (argc < 2) {
        fprintf(stderr, "Specify a filename\n");
        exit(1);
    }

    char const* filename = argv[1];
    struct stat fs = {0};
    int r = stat(filename, &fs);
    if (r == -1) {
        fprintf(stderr, "Error reading \"%s\"\n", filename);
        exit(1);
    }

    printf("Permissions for file \"%s\": ", filename);

    permissions_out(fs.st_mode);
    putchar('\n');

    return 0;
}
