#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void line_out(int offset, size_t len, unsigned char const data[len]) {
    printf("%05x ", offset);

    for (int i = 0; i < len; i += 1) {
        printf(" %02x", data[i]);
        if ((i + 1) % 8 == 0) {
            putchar(' ');
        }
    }

    putchar(' ');

    for (int i = 0; i < len; i += 1) {
        if (' ' <= data[i] && data[i] <= '~') {
            putchar(data[i]);
        } else {
            putchar(' ');
        }
    }

    putchar('\n');
}

#define SIZE 256
int main() {
    srand(time((void*)0));
    unsigned char data[SIZE];

    for (int i = 0; i < SIZE; i += 1) {
        int r = rand() % SIZE;
        data[i] = r;
    }

    for (int i = 0; i < SIZE; i += 16) {
        line_out(i, 16, data + i);
    }

    return 0;
}
