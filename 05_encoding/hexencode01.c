#include <stdio.h>

#define BYTES_PER_LINE 18

int main() {
    printf("HEX ENCODE v1.0\n");
    int bytes = 0;
    for (int ch = getchar(); ch != EOF; ch = getchar()) {
        printf(" %02x", ch);
        bytes += 1;
        if (bytes == BYTES_PER_LINE) {
            putchar('\n');
            bytes = 0;
        }
    }
    printf("\nHEX ENCODE END\n");

    return 0;
}
