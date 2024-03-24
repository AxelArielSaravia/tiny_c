#include <stdio.h>
#include <ctype.h>

#define WORD_SIZE 64

int main() {
    char word[WORD_SIZE];
    int offset = 0;
    int ch = getchar();
    while (ch != EOF) {
        if (isspace(ch)) {
            word[offset] = '\0';
            if (offset > 0) {
                printf("%s\n", word);
                offset = 0;
            }
        } else {
            word[offset] = ch;
            offset += 1;
            if (offset == WORD_SIZE - 1) {
                word[offset] = '\0';
                printf("%s\n", word);
                offset = 0;
            }
        }
        ch = getchar();
    }
    return 0;
}
