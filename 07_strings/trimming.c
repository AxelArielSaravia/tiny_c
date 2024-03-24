#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void left(size_t const len, char dest[static 1], char src[static 1]) {
    size_t i = 0;
    while (i < len) {
        if (!src[i]) {
            break;
        }
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = '\0';
}

void right(size_t len, char dest[static 1], char src[static 1]) {
    size_t src_len = 0;
    while (src[src_len]) {
        src_len += 1;
    }
    if (src_len < len) {
        len = src_len;
    }
    size_t offset = src_len - len;
    size_t i = 0;
    while (i < len) {
        if (!src[i + offset]) {
            break;
        }
        dest[i] = src[i + offset];
        i += 1;
    }
    dest[i] = '\0';
}

void mid(size_t len, char dest[static 1], char src[static 1], size_t offset) {
    size_t i = 0;
    while (i < len) {
        if (!src[i + offset]) {
            break;
        }
        dest[i] = src[i + offset];
        i += 1;
    }
    dest[i] = '\0';
}

int main() {
    char str[] = "Slice me, dice me, make julienne fries!";
    char lf_buff[32];
    char rg_buff[32];
    char m_buff[32];

    left(8, lf_buff, str);
    right(20, rg_buff, str);
    mid(7, m_buff, str, 10);

    printf("original    : %s\n", str);
    printf("left 8      : %s\n", lf_buff);
    printf("right 20    : %s\n", rg_buff);
    printf("mid 7 off10 : %s\n", m_buff);

    return 0;
}
