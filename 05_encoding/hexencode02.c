#include <stdio.h>

#define BYTES_PER_LINE 18

int main() {
    printf("HEX ENCODE v2.0\n");
    int bytes = 0;
    int sum = 0;
    for (int ch = getchar(); ch != EOF; ch = getchar()) {
        printf(" %02x", ch);
        bytes += 1;
        sum += ch;
        if (bytes == BYTES_PER_LINE) {
            printf(" %02x\n", sum % 0x100);
            bytes = 0;
            sum = 0;
        }
    }
    if (0 < bytes) {
        printf(" %02x\n", sum % 0x100);
    }
    printf("HEX ENCODE END\n");

    return 0;
}
