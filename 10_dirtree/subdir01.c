#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char const* argv[argc]) {
    if (argc < 2) {
        fprintf(stderr, "Missing directory name\n");
        exit(1);
    }
    char const* dirname = argv[1];
    DIR* dp = opendir(dirname);
    if (!dp) {
        fprintf(stderr, "Unable to read directory \"%s\"\n", dirname);
        exit(1);
    }

    char const* filename = 0;
    struct stat fs = {0};
    struct dirent* entry = readdir(dp);
    while (entry) {
        filename = (*entry).d_name;
        int r = stat(filename, &fs);
        if (r == -1) {
            fprintf(stderr, "Error on \"%s\"\n", filename);
            exit(1);
        }
        if (S_ISDIR(fs.st_mode)) {
            printf("Found directory: %s\n", filename);
        }

        entry = readdir(dp);
    }
    closedir(dp);

    return 0;
}
