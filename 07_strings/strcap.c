#include <stdio.h>
#include <stdlib.h>

void strcap(char str[static 1]) {
    _Bool isSWord = 0;
    _Bool prevWhite = 1;
    while (*str) {
        if (*str == ' ' || *str == '\n' || *str == '\t') {
            prevWhite = 1;
        } else if (prevWhite) {
            isSWord = 1;
            prevWhite = 0;
        }
        if (isSWord) {
            if ('a' <= *str && *str <= 'z') {
                *str &= 0xdf;
            }
            isSWord = 0;
        }
        str += 1;
    }
}

int main() {
    char str[] = "elements in a park";
    strcap(str);
    char buff[32] = {0};
    printf("%s\n", str);
    return 0;
}
