#include <ctype.h>
#include <stdio.h>

#define ASCII_VALUES 128

int main(int argc, char* argv[argc]) {
    unsigned col = 1;
    if (2 < argc) {
        char* command = argv[1];
        char* value = argv[2];
        if (command[0] == '-' && command[1] == 'c' && command[2] == 0) {
            if ((value[0] == '2' || value[0] == '4') && value[1] == 0) {
                col = value[0] - 48;
            }
        }
    }
    printf("Dec Oct Hex C");
    for (int i = 1; i < col; i += 1) {
        printf(" | Dec Oct Hex C");
    }
    putchar('\n');

    unsigned col_size = ASCII_VALUES / col;
    unsigned char n = 0;
    unsigned v = 0;
    char c = '-';

    while (n < col_size) {
        if (39 < n) {
            c = n;
        }
        v = 0;
        printf("%3d %3o %3x %c", n, n, n, c);
        for (int i = 1; i < col; i += 1) {
            v += col_size;
            printf(" | %3d %3o %3x %c", n+v, n+v, n+v, n+v);
        }
        putchar('\n');
        n += 1;
    }
    return 0;
}
