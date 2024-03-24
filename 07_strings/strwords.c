#include <stdio.h>
#include <ctype.h>

int strwords(char s[static 1]) {
    _Bool inword = 0;
    int count = 0;
    int i = 0;
    while (s[i]) {
        if (isalpha(s[i])) {
            if (!inword) {
                count += 1;
                inword = 1;
            }
        } else {
            inword = 0;
        }
        i += 1;
    }
    return count;
}

int main() {
    char str[] = "this is a sample string";
    printf("The string '%s' contains %d words\n", str, strwords(str));

    return 0;
}
