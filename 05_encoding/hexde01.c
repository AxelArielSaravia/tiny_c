#include <stdio.h>

int tohex(int c) {
    if ('0' <= c && c <= '9') {
        return c - '0';
    }
    if ('A' <= c && c <= 'F') {
        return c - 'A' + 0x0A;
    }
    if ('a' <= c && c <= 'f') {
        return c - 'a' + 0x0A;
    }
    return -1;
}

int main() {
    int ch;
    int a;
    int b;
    while (1) {
        ch = getchar();
        if(ch == EOF) {
            break;
        }
        a = tohex(ch);
        if(a < 0) {
            break;
        }
        a <<= 4;
        ch = getchar();
        if(ch == EOF) {
            break;
        }
        b = tohex(ch);
        if(b < 0) {
            break;
        }
        putchar(a + b);
    }
    return 0;
}
