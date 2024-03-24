#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NATOS_LEN 26
char const*const nato[NATOS_LEN] = {
    "Alfa",
    "Bravo",
    "Charlie",
    "Delta",
    "Echo",
    "Foxtrot",
    "Golf",
    "Hotel",
    "India",
    "Juliett",
    "Kilo",
    "Lima",
    "Mike",
    "November",
    "Oscar",
    "Papa",
    "Quebec",
    "Romeo",
    "Sierra",
    "Tango",
    "Uniform",
    "Victor",
    "Whiskey",
    "Xray",
    "Yankee",
    "Zulu"
};

char isterm(char const* term);

#define MAX_NATO_SIZE 8
int main(int argc, char* argv[argc]) {
    if (argc < 2) {
        fprintf(stderr, "please supply a text file argument\n");
        exit(1);
    }
    FILE* f = fopen(argv[1], "r");
    if (!f) {
        fprintf(stderr, "unable to open '%s'\n", argv[1]);
        exit(1);
    }
    char word[MAX_NATO_SIZE + 1];
    int offset = 0;
    for (int ch = fgetc(f); ch != EOF; ch = fgetc(f)) {
        if (isalpha(ch)) {
            if (offset < MAX_NATO_SIZE) {
                word[offset] = ch;
                offset += 1;
            } else {
                offset = 0;
            }
            //if (offset >= WORD_SIZE) {
            //    fprintf(stderr, "buffer overflow\n");
            //    exit(1);
            //}
        } else {
            if (0 < offset) {
                word[offset] = '\0';
                putchar(isterm(word));
                offset = 0;
            }
        }
    }
    putchar('\n');
    return 0;
}

char isterm(char const* term) {
    char const* t = term;
    int i = (*t | 0x20) - 'a';
    if (0 <= i && i < NATOS_LEN) {
        char const* n = nato[i];
        while (
            *n != '\0'
            && (*n | 0x20) == (*t | 0x20) //insensitive comparition
        ) {
            n += 1;
            t += 1;
        }
        if (*n == '\0') {
            return *nato[i];
        }
    }
    return '\0';
}
