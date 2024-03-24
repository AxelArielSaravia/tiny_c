#include <stdio.h>

int main() {
    int ch = getchar();
    int wrap = 0;
    while (ch != EOF) {
        printf("%02x ", ch);
        wrap += 3;
        if (77 < wrap || ch == '\n') {
            putchar('\n');
            wrap = 0;
        }
        ch = getchar();
    }
    return 0;
}
