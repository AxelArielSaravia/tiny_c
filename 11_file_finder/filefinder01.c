#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

#ifdef PATH_MAX
    #undef PATH_MAX
#endif
#define PATH_MAX 256

int count = 0;

void find(char const* dirpath, char const* parentpath, char const* match) {
    DIR* dp = opendir(dirpath);
    if (!dp) {
        fprintf(stderr, "Unable to read directory \"%s\"\n", dirpath);
        exit(1);
    }

    char subdirpath[PATH_MAX];
    struct stat fs = {0};
    struct dirent* entry = readdir(dp);
    while (entry) {
        if (strcmp(entry->d_name, match) == 0) {
            printf("%s/%s\n", dirpath, match);
            count += 1;
        }
        stat(entry->d_name, &fs);
        if (S_ISDIR(fs.st_mode) && entry->d_name[0] != '.') {
            if (chdir(entry->d_name) == -1) {
                fprintf(stderr, "Unable to change to %s\n", entry->d_name);
                exit(1);
            }
            getcwd(subdirpath, BUFSIZ);
            find(subdirpath, dirpath, match);
        }
        entry = readdir(dp);
    }
    closedir(dp);

    if (!parentpath) {
        return;
    }
    if (chdir(parentpath) == -1) {
        fprintf(stderr, "Parent directory lost\n");
        exit(1);
    }
}

int main(int argc, char const* argv[argc]) {
    if (argc < 2) {
        fprintf(stderr, "Format: ff filename\n");
        exit(1);
    }
    char current[PATH_MAX];
    getcwd(current, PATH_MAX);
    if (chdir(current) == -1) {
        fprintf(stderr, "Unable to access directory %s\n", current);
        exit(1);
    }
    printf("Searching for \"%s\"\n", argv[1]);

    find(current, (void*)0, argv[1]);

    printf(" Found %d match", count);
    if (count != 1) {
        printf("es");
    }
    putchar('\n');

    return 0;
}
