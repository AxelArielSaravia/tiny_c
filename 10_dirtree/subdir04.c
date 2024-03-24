#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

void dir(char const*const dirname) {
    if (chdir(dirname) == -1) {
        fprintf(stderr, "Unable to change to %s\n", dirname);
        exit(1);
    }

    char directory[BUFSIZ];
    getcwd(directory, BUFSIZ);

    DIR* dp = opendir(directory);
    if (!dp) {
        fprintf(stderr, "Unable to read directory \"%s\"\n", directory);
        exit(1);
    }

    printf("%s\n", directory);

    struct stat fs = {0};
    struct dirent* entry = readdir(dp);
    while (entry) {
        char const* filename = (*entry).d_name;
        if (filename[0] != '.') {
            stat(filename, &fs);
            if (S_ISDIR(fs.st_mode)) {
                dir(filename);
            }
        }
        entry = readdir(dp);
    }
    closedir(dp);

    if (chdir("..") == -1) {
        fprintf(stderr, "Parent directory lost\n");
        exit(1);
    }
}

int main(int argc, char const* argv[argc]) {
    if (argc < 2) {
        dir(".");
    } else {
        dir(argv[1]);
    }

    return 0;
}
