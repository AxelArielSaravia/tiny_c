#include <ctype.h>
#include <stdio.h>

int main(int argc, char* argv[argc]) {
    int shift = 13;
    if (3 <= argc) {
        int a = argv[2][0];
        int b = argv[1][0];
        if (isalpha(a) && isalpha(b)) {
            shift = (a | 0x20) - (b | 0x20);
            if (shift < -25 && 25 < shift) {
                shift = 13;
            }
        }
    }
    int ch = getchar();
    while (ch != EOF) {
        if (isupper(ch)) {
            ch += shift;
            if (ch < 'A') {
                ch += 26;
            } else if ('Z' < ch) {
                ch -= 26;
            }
        } else if (islower(ch)) {
            ch += shift;
            if (ch < 'a') {
                ch += 26;
            } else if ('z' < ch) {
                ch -= 26;
            }
        }
        putchar(ch);
        ch = getchar();
    }
    return 0;
}
