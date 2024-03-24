#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    DIR* dp = opendir(".");
    if (!dp) {
        fprintf(stderr, "Unable to read .");
        exit(1);
    }

    struct dirent* entry = readdir(dp);
    while (entry) {
        printf("File %s\n", (*entry).d_name);
        entry = readdir(dp);
    }
    closedir(dp);

    return 0;
}
