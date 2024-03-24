#include <stdio.h>

void strtabs(char const s[static 1], int tab) {
    int column = 0;
    int spaces = 0;
    int i = 0;
    while (*s) {
        if (*s == '\t') {
            spaces = tab - (column % tab);
            for (i = 0; i < spaces; i += 1) {
                putchar(' ');
            }
            column += spaces;
        } else {
            putchar(*s);
            if (*s == '\n') {
                column = 0;
            } else {
                column += 1;
            }

        }
        s += 1;
    }
}

void strtabs2(char const s[static 1], int tab) {
    int column = 0;
    int spaces = 0;
    int i = 0;
    while (*s) {
        if (column == tab) {
            column = 0;
        }
        if (*s == '\t') {
            spaces = tab - column;
            for (i = 0; i < spaces; i += 1) {
                putchar(' ');
            }
            column += spaces;
        } else {
            putchar(*s);
            if (*s == '\n') {
                column = 0;
            } else {
                column += 1;
            }

        }
        s += 1;
    }
}

int main() {
    char const*const text[3] = {
        "Hello\tHi\tHowdy\n",
        "\tLa\tLa\n",
        "Constantinople\tConstantinople\n"
    };
    for (int y = 4; y < 32; y *= 2) {
        printf("Tab width: %d\n", y);
        for (int x = 0; x < 3; x += 1) {
            strtabs(text[x], y);
        }
    }
    return 0;
}
