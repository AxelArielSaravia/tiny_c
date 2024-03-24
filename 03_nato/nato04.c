#include <stdio.h>
#include <string.h>

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

#define PHRASE_SIZE 64
int main(int argc, char* argv[argc]) {
    printf("NATO word or phrase (less than %d chars): ", PHRASE_SIZE);

    char phrase[PHRASE_SIZE];
    fgets(phrase, PHRASE_SIZE, stdin);

    char const* match = strtok(phrase, " ");
    while (match) {
        char ch = isterm(match);
        if (ch != '\0') {
            putchar(ch);
        }
        match = strtok((void*)0, " ");
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

