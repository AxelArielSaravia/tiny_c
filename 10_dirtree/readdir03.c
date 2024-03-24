#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    DIR* dp = opendir(".");
    if (!dp) {
        fprintf(stderr, "Unable to read directory\n");
        exit(1);
    }

    struct stat fs = {0};
    struct dirent* entry = readdir(dp);
    while (entry) {
        char const* filename = (*entry).d_name;
        int r = stat(filename, &fs);
        if (r == -1) {
            fprintf(stderr, "Error reading \"%s\"\n", filename);
            exit(1);
        }
        if (S_ISDIR(fs.st_mode)) {
            printf("Dir  %-16s ", filename);
        } else {
            printf("File %-16s ", filename);
        }
        printf("%8lu bytes ", fs.st_size);
        printf("%s", ctime(&fs.st_atime));

        entry = readdir(dp);
    }
    closedir(dp);

    return 0;
}
