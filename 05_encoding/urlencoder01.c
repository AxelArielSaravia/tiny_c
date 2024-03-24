#include <stdio.h>
#include <ctype.h>

int main() {
    for (int ch = getchar(); ch != EOF; ch = getchar()) {
        if (ch == '-' || ch == ',' || ch == '_' || ch == '*' || isalnum(ch)) {
            putchar(ch);
        } else {
            printf("%%%02x", ch);
        }
    }
    return 0;
}
