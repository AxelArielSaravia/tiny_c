#include <stdio.h>

int main() {
    char sentence[] = "ASCII makes my heart beat faster\n";
    char* s = sentence;
    while (*s) {
        if ('A' <= *s && *s <= 'Z') {
            putchar(*s | 0x20);
        } else {
            putchar(*s);
        }
        s += 1;
    }
    s = sentence;
    while (*s) {
        if ('a' <= *s && *s <= 'z') {
            putchar(*s & 0xdf);
        } else {
            putchar(*s);
        }
        s += 1;
    }
    return 0;
}
