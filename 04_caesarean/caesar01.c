#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[argc]) {
    int ch = getchar();
    while (ch != EOF) {
        if (isalpha(ch)) {
            if ( 'a' <= (ch | 0x20) &&  (ch | 0x20)<= 'm') {
                ch += 13;
            } else {
                ch -= 13;
            }
        }
        putchar(ch);
        ch = getchar();
    }
    return 0;
}
