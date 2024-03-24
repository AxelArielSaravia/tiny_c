#include <stdio.h>
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

int main() {
    char ch = getchar();
    while (ch != EOF) {
        if (isalpha(ch)) {
            printf("%s ", nato[toupper(ch) - 'A']);
        }
        if (ch == '\n') {
            putchar(ch);
        }
        ch = getchar();
    }
    putchar('\n');

    return 0;
}
