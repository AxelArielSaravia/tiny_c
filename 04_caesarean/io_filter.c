#include <stdio.h>

int main(int argc, char* argv[argc]) {
    int ch = getchar();
    while (ch != EOF) {
        putchar(ch);
        ch = getchar();
    }
    return 0;
}
