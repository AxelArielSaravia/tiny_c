#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


#define PRHASE_SIZE 80
int main(int argc, char* argv[argc]) {
    if (argc < 2) {
        fprintf(stderr, "please supply a text file argument\n");
        exit(1);
    }
    FILE* f = fopen(argv[1], "r");
    if (!f) {
        fprintf(stderr, "Unable to open '%s'\n", argv[1]);
        exit(1);
    }
    char phrase[PRHASE_SIZE];
    char* match;
    while (!feof(f)) {
        fgets(phrase, PRHASE_SIZE, f);
        match = strtok(phrase, " ,.!?=(){}[]'\"");
        while (match) {
            char ch = isterm(match);
            if (ch != '\0') {
                putchar(ch);
            }
            match = strtok(0, " ");
        }
    }
    putchar('\n');
    return 0;
}

char isterm(char const* term) {
    char const* t = term;
    int i = (*t | 0x20) - 97;
    if (0 <= i && i < NATOS_LEN) {
        char const* n = nato[i];
        while (*n != 0 && (*n | 0x20) == (*t | 0x20)) {
            n += 1;
            t += 1;
        }
        if (*n == '\0') {
            return *nato[i];
        }
    }
    return '\0';
}
