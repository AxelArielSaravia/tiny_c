#include <stdio.h>

int main() {
    unsigned char data[256];
    for (int i = 0; i < 256; i += 1) {
        data[i] = i;
    }
    for (int i = 0; i < 256; i += 1) {
        printf("%d\n", data[i]);
    }

    return 0;
}
