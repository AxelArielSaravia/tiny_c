#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSW_MAX 5

int main(int argc, char* argv[argc]) {
    if (argc < 2) {
        fprintf(stderr, "A password must be provided\n");
        exit(-1);
    }
    char const* passw = argv[1];
    int i = 0;
    for (; i < PASSW_MAX + 1 && passw[i] != '\0'; i += 1) {
        if (passw[i] < 'a' || 'z' < passw[i]) {
            fprintf(stderr, "The password only can have 'a' to 'z' characters\n");
            exit(-1);
        }
    }
    if (i != PASSW_MAX || passw[PASSW_MAX] != '\0') {
        fprintf(stderr, "The password must have %d characters\n", PASSW_MAX);
        exit(-1);
    }

    char buff[PASSW_MAX + 1];
    buff[PASSW_MAX] = '\0';
    for (int j = 0; j < PASSW_MAX; j += 1) {
        buff[j] = 'a';
    }

    int pos = 0;
    int rel_pos = 0;
    while (pos < PASSW_MAX && strcmp(passw, buff) != 0) {
        while (buff[rel_pos] == 'z') {
            buff[rel_pos] = 'a';
            if (rel_pos < pos) {
                rel_pos += 1;
            } else {
                pos += 1;
                if (pos == PASSW_MAX) {
                    printf("We can not guesses the pasword\n");
                    return 0;
                }
                rel_pos = pos;
            }
        }
        buff[rel_pos] += 1;
        if (rel_pos > 0) {
            rel_pos = 0;
        }
    }
    printf("The password is: %s\n", buff);
    return 0;
}
