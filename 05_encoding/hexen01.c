#include <stdio.h>

int main() {
    for (int ch = getchar(); ch != EOF; ch = getchar()) {
        printf("%02x", ch);
    }
    putchar('\n');
    return 0;
}
