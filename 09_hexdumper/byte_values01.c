#include <stdio.h>

int main() {
    unsigned char v = 0;
    while (1) {
        printf("%d\n", v);
        if (v == 255) {
            break;
        }
        v += 1;
    }
    return 0;
}
