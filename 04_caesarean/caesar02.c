#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[argc]) {
    int shift = 'D' - 'A';
    int ch = getchar();
    while (ch != EOF) {
        if (isalpha(ch)) {
            ch += shift;
            if (('Z' < ch && ch < 'a') || 'z' < ch) {
                ch -= 26;
            }
        }
        putchar(ch);
        ch = getchar();
    }
    return 0;
}
