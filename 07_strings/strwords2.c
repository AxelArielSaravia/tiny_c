#include <stdio.h>
#include <stdlib.h>

int strwords(char s[static 1]) {
    _Bool isword = 0;
    _Bool prevWhite = 1;
    int count = 0;
    while (*s) {
        if (*s == ' ' || *s == '\n' || *s == '\t') {
            prevWhite = 1;
        } else if (prevWhite) {
            isword = 1;
            prevWhite = 0;
        }
        if (isword) {
            count += 1;
            isword = 0;
        }
        s += 1;
    }
    return count;
}

int main() {
    char str[] = "This isn't 89a sample string";
    printf("The string '%s' contains %d words\n", str, strwords(str));

    return 0;
}
