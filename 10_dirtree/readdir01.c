#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

int main() {
    DIR* dp = opendir(".");
    if (!dp) {
        puts("Unable to read directory");
        exit(1);
    }

    struct dirent* entry = readdir(dp);
    printf("File %s\n", (*entry).d_name);

    closedir(dp);

    return 0;
}
