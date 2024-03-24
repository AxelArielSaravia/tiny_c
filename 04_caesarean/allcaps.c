#include <stdio.h>

int main() {
    int ch = getchar();
    while (ch != '\n') {
        if (96 < ch && ch < 123) {
            putchar(ch - 32);
        } else {
            putchar(ch);
        }
        ch = getchar();
    }
    putchar('\n');
    return 0;
}
