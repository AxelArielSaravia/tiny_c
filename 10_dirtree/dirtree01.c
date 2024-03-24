#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

char const* extract(char const* path) {
    int len = strlen(path);
    if (len == 0) {
        return (void*)0;
    }
    if (len == 1 && path[0] == '/') {
        return path;
    }
    int i = len - 1;
    while (0 < i && path[i] != '/') {
        i -= 1;
    }

    if (i == 0 || path[i+1] == '\0') {
        return (void*)0;
    } else {
        return &path[i];
    }
}

void dir(char const*const dirpath, char const*const parentpath) {
    DIR* dp = opendir(dirpath);
    if (!dp) {
        fprintf(stderr, "Unable to read directory \"%s\"\n", dirpath);
        exit(1);
    }

    printf("%s\n", extract(dirpath));

    char subdirpath[BUFSIZ];
    struct stat fs = {0};
    struct dirent* entry = readdir(dp);
    while (entry) {
        if (entry->d_name[0] != '.') {
            stat(entry->d_name, &fs);
            if (S_ISDIR(fs.st_mode)) {
                if (chdir(entry->d_name) == -1) {
                    fprintf(stderr, "Unable to change to %s\n", entry->d_name);
                    exit(1);
                }
                getcwd(subdirpath, BUFSIZ);
                dir(subdirpath, dirpath);
            }
        }
        entry = readdir(dp);
    }
    closedir(dp);

    if (parentpath && chdir(parentpath) == -1) {
        fprintf(stderr, "Parent directory lost\n");
        exit(1);
    }
}

int main(int argc, char const* argv[argc]) {
    if (1 < argc && chdir(argv[1]) == -1) {
        fprintf(stderr, "Unable to access to %s\n", argv[1]);
        exit(1);
    }
    char current[BUFSIZ];
    getcwd(current, BUFSIZ);
    dir(current, (void*)0);

    return 0;
}
