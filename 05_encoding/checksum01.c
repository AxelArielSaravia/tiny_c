#include <stdio.h>

int hexbytes[] = {
    0x41,
    0x42,
    0x43,
    0x44,
    0x45,
    0x46,
    0x47,
    0x48,
    0x49,
    0x4a,
};

int main() {
    int checksum = 0;
    for (int x = 0; x < 10; x += 1) {
        checksum += hexbytes[x];
        printf(" %02x", hexbytes[x]);
    }
    putchar('\n');
    int res = checksum % 0x100;
    printf("Checksum = %02x -> %d\n", res, res);
    return 0;
}
