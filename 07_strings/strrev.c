#include <stdio.h>
#include <stdlib.h>

void strrev(char s[static 1]) {
    size_t len = 0;
    while (s[len] != '\0') {
        len += 1;
    }
    char temp = 0;
    for (size_t i = 0; i < (len / 2); i += 1) {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

int main() {
    char str[] = "A string dwelling in memory";
    printf("%s\n", str);
    strrev(str);
    printf("%s\n", str);
    return 0;
}
