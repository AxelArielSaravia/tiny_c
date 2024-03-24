#include <stdio.h>

int main() {
    int ch = getchar();
    while (ch != EOF) {
        printf("%02x ", ch);
        ch = getchar();
    }
    return 0;
}
