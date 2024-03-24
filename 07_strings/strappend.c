#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct String String;
struct String {
    size_t len;
    size_t cap;
    char* v;
};

void strappend(
    char    src1[static 1],
    char    src2[static 1],
    size_t  len,
    char    dest[static len]
) {
    size_t min_len = 0;
    size_t c = 0;
    size_t s1_len = strlen(src1);
    size_t s2_len = strlen(src2);

    if (len - 1 < s1_len) {
         min_len = len - 1;
    } else {
        min_len = s1_len;
    }
    memcpy(dest, src1, min_len);
    c += min_len;

    if (len - 1 - c < s2_len) {
        min_len = len - 1 - c;
    } else {
        min_len = s2_len;
    }
    if (min_len > 0) {
        memcpy((dest + c), src2, min_len);
        c += min_len;
    }

    dest[c] = '\0';
}

int main() {
    char s1[] = "This is another ";
    char s2[] = "fine mess! moprnas erasdnenersda";
    char buff[32] = {0};

    strappend(s1, s2, 32, buff);

    printf("%s\n", buff);

    return 0;
}
