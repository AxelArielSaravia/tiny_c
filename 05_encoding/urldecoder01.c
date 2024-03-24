#include <stdio.h>
#include <ctype.h>

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
            putchar((a << 4) + b);
        } else {
            putchar(ch);
        }
   }
    return 0;
}
