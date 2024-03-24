#include <stdio.h>
#include <stdlib.h>

#define SIZE 256

int main() {
    unsigned char data[SIZE];
    for (int i = 0; i < SIZE; i += 1) {
        data[i] = i;
    }
    for (int i = 0; i < SIZE; i += 1) {
        printf(" %02x", data[i]);
        if ((i + 1) % 16 == 0) {
            putchar('\n');
        }
    }

    return 0;
}
