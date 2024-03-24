#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[argc]) {
    int shift = 'D' - 'A';
    int ch = getchar();
    while (ch != EOF) {
        if (isalpha(ch)) {
            ch -= shift;
            if (ch < 'A' || ('Z' < ch && ch < 'a')) {
                ch += 26;
            }
        }
        putchar(ch);
        ch = getchar();
    }
    return 0;
}
