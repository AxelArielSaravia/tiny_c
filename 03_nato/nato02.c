#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char const* nato[] = {
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

int main(int argc, char* argv[argc]) {
    if (argc < 2) {
        fprintf(stderr, "please supply a text file argument\n");
        exit(1);
    }
    FILE* n = fopen(argv[1], "r");
    if (!n) {
        fprintf(stderr, "Unable to open '%s'\n", argv[1]);
        exit(1);
    }
    for (int ch = fgetc(n); ch != EOF; ch = fgetc(n)) {
        if (isalpha(ch)) {
            printf("%s ", nato[toupper(ch) - 'A']);
        }
    }
    putchar('\n');

    return 0;
}
