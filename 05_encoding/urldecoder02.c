#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int tohex(char c) {
    if ('0' <= c && c <= '9') {
        return c - '0';
    }
    if ('A' <= c && c <= 'F') {
        return (c - 'A') + 0xa;
    }
    if ('a' <= c && c <= 'f') {
        return (c - 'a') + 0xa;
    }
    return -1;
}

int main() {
    for (int ch = getchar(); ch != EOF; ch = getchar()) {
        if (ch == '%') {
            ch = getchar();
            if (ch == EOF) {
                break;
            }
            int a = tohex(ch);
            ch = getchar();
            if (ch == EOF) {
                break;
            }
            int b = tohex(ch);
            if (a < 0 && b < 0) {
                fprintf(stderr, "Invalid hexcode\n");
                exit(-1);
                break;
            }
            putchar((a << 4) + b);
        } else {
            if (ch == '-' || ch == ',' || ch == '_' || ch == '*' || isalnum(ch)) {
                putchar(ch);
            } else {
                fprintf(stderr, "Invalid character\n");
                exit(-1);
                break;
            }
        }
    }
    return 0;
}
