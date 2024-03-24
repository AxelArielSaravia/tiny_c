#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

typedef struct finfo finfo;
struct finfo {
    int     index;
    int     repeat;
    char    name[BUFSIZ];
    char    path[PATH_MAX];
    finfo*  next;
    finfo*  nrep;
};

finfo* find(char const* dirpath, char const* parentpath, finfo* fi) {
    DIR* dp = opendir(dirpath);
    if (!dp) {
        fprintf(stderr, "Unable to read directory \"%s\"\n", dirpath);
        exit(1);
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
            fi = find(subdirpath, dirpath, fi);
        } else {
            finfo* next = calloc(1, sizeof *next);
            if (!next) {
                fprintf(stderr, "Unable to allocate new structure\n");
                exit(1);
            }
            *next = (finfo){
                .index = fi->index + 1,
                .repeat = 1,
                .next = (void*)0,
                .nrep = (void*)0,
            };
            strcpy(next->name, entry->d_name);
            strcpy(next->path, dirpath);
            fi->next = next;
            fi = next;
        }
    }
    closedir(dp);

    if (parentpath && chdir(parentpath) == -1) {
        fprintf(stderr, "Parent directory lost\n");
        exit(1);
    }

    return fi;
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

    if (chdir(startdir) == -1) {
        fprintf(stderr, "Unable to access directory %s\n", startdir);
        exit(1);
    }

    find(startdir, (void*)0, first);

    _Bool found = (_Bool)0;
    finfo* current = first->next;
    finfo* ftemp = &(finfo){0};
    finfo* ctemp = ftemp;
    while (current) {
        if (current->repeat == 1) {
            finfo* scan = current->next;
            while (scan) {
                if (scan->repeat == 1 && strcmp(current->name, scan->name) == 0) {
                    if (current->repeat == 1) {
                        ctemp->nrep = current;
                        ctemp = current;
                    }
                    ctemp->nrep = scan;
                    ctemp = scan;
                    current->repeat += 1;
                    scan->repeat = current->repeat;
                    found = (_Bool)1;
                }
                scan = scan->next;
            }
        }
        current = current->next;
    }

    if (!found) {
        puts("No duplicates found");
        return 1;
    }

    ctemp = ftemp->nrep;
    char* name = 0;
    while (ctemp) {
        if (name && strcmp(name, ctemp->name) == 0) {
            printf(" %s/%s\n", ctemp->path, ctemp->name);
        } else {
            name = ctemp->name;
            printf("%d duplicates found of %s:\n", ctemp->repeat, ctemp->name);
            printf(" %s/%s\n", ctemp->path, ctemp->name);
        }
        ctemp = ctemp->nrep;
    }

    return 0;
}

