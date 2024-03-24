#include <stdio.h>
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

int main() {
    #define count 4
    char const* pathname[count] = {
        "/home/dang",
        "/usr/local/this/that",
        "/",
        "nothing here"
    };
    for (int x = 0; x < count; x += 1) {
        printf("%s -> %s\n", pathname[x], extract(pathname[x]));
    }
    return 0;
}
