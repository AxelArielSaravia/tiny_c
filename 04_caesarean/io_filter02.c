#include <stdio.h>

int main(int argc, char* argv[argc]) {
    int ch = getchar();
    while (ch != EOF) {
        switch (ch) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                putchar('*');
                break;
            default:
                putchar(ch);
        }
        ch = getchar();
    }
    return 0;
}
