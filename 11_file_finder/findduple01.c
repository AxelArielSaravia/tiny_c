#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

typedef struct finfo finfo;
struct finfo {
    int index;
    char name[BUFSIZ];
    char path[PATH_MAX];
    finfo* next;
};

void find(char const* dirpath, char const* parentpath, finfo* fi) {
    DIR* dp = opendir(dirpath);
    if (!dp) {
        fprintf(stderr, "Unable to read directory \"%s\"\n", dirpath);
        exit(1);
        //Will free memory as it exits
    }

    char subdirpath[BUFSIZ];
    struct stat fs = {0};
    for (struct dirent* entry = readdir(dp); entry; entry = readdir(dp)) {
        stat(entry->d_name, &fs);
        if (S_ISDIR(fs.st_mode)) {
            if (entry->d_name[0] == '.') {
                continue;
            }
            if (chdir(entry->d_name) == -1) {
                fprintf(stderr, "Unable to change to %s\n", entry->d_name);
                exit(1);
            }
            getcwd(subdirpath, BUFSIZ);
            find(subdirpath, dirpath, fi);
        } else {
            finfo* next = calloc(1, sizeof *next);
            if (!next) {
                fprintf(stderr, "Unable to allocate new structure\n");
                exit(1);
            }
            *next = (finfo){
                .index = fi->index + 1,
                .next = (void*)0,
            };
            strcpy(next->name, entry->d_name);
            strcpy(next->path, dirpath);
            fi->next = next;
            fi = next;
        }
    }
    closedir(dp);

    if (chdir(parentpath) == -1) {
        if (!parentpath) {
            return;
        }
        fprintf(stderr, "Parent directory lost\n");
        exit(1);
    }
}

int main() {
    finfo* first = calloc(1, sizeof *first);
    if (!first) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }
    *first = (finfo){0};

    char startdir[PATH_MAX];
    getcwd(startdir, PATH_MAX);

    if(chdir(startdir) == -1) {
        fprintf(stderr, "Unable to access directory %s\n", startdir);
        exit(1);
    }

    find(startdir, (void*)0, first);

    finfo* current = first;
    while (current) {
        if (0 < current->index) {
            printf( "%d:%s/%s\n", current->index, current->path, current->name);
        }
        current = current->next;
    }
    return 0;
}
