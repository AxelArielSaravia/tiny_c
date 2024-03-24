#include <stdio.h>

void strupper(char s[static 1]) {
    while (*s) {
        if ('a' <= *s && *s <= 'z') {
            *s &= 0xdf;
        }
        s += 1;
    }
}

int main() {
    char string[] = "Random String sample 1234*($";
    printf("Original string %s\n", string);

    strupper(string);
    printf("Uppercase string %s\n", string);

    return 0;
}
