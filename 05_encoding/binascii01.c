#include <stdio.h>

char* binString(char a) {
    static char buf[9];
    buf[8] = '\0';
    int i = 0;
    while (i < 8) {
        if (a & 0x80) {
            buf[i] = '1';
        } else {
            buf[i] = '0';
        }
        a <<= 1;
        i += 1;
    }
    return buf;
}

int main() {
    for (int a = 0; a < 32; a += 1) {
        printf("%3d %02X %s - | ",     a,    a, binString(a));
        printf("%3d %02X %s %c | ", a+32, a+32, binString(a+32), a+32);
        printf("%3d %02X %s %c | ", a+64, a+64, binString(a+64), a+64);
        printf("%3d %02X %s %c\n",  a+96, a+96, binString(a+96), a+96);
    }
    return 0;
}
