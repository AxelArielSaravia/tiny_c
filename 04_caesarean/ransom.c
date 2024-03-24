#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int ch = getchar();
    srand((unsigned)time((void*)0));
    int r;
    while (ch != '\n' && ch != EOF) {
        r = rand() % 2;
        if (r) {
            putchar(toupper(ch));
        } else {
            putchar(tolower(ch));
        }
        ch = getchar();
    }
    putchar('\n');
    return 0;
}
