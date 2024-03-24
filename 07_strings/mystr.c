#include "./mystr.h"

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

void strcap(char str[static 1]) {
    bool isSWord = false;
    bool prevWhite = true;
    while (*str) {
        if (*str == ' ' || *str == '\n' || *str == '\t') {
            prevWhite = true;
        } else if (prevWhite) {
            isSWord = true;
            prevWhite = false;
        }
        if (isSWord) {
            if ('a' <= *str && *str <= 'z') {
                *str &= 0xdf;
            }
            isSWord = false;
        }
        str += 1;
    }
}

void strinsert(
    size_t offset,
    char src[static 1],
    char ins[static 1],
    char dest[static 1]
) {
    if (offset < 0) {
        return;
    }
    memcpy(dest, src, offset);
    dest[offset] = '\0';
    strcat(dest, ins);
}

void strupper(char s[static 1]) {
    while (*s) {
        if ('a' <= *s && *s <= 'z') {
            *s &= 0xdf;
        }
        s += 1;
    }
}

void strlower(char s[static 1]) {
    while (*s) {
        if ('A' <= *s && *s <= 'Z') {
            *s += 32;
        }
        s += 1;
    }
}

void strrev(char s[static 1]) {
    size_t len = 0;
    while (s[len] != '\0') {
        len += 1;
    }
    char temp = 0;
    for (size_t i = 0; i < (len / 2); i += 1) {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

bool strsplit(
    size_t offset,
    char src[static 1],
    char dest1[static 1],
    char dest2[static 1]
) {
    size_t len = strlen(src);
    if (len < offset) {
        return false;
    }
    memcpy(dest1, src, offset);
    memcpy(dest2, src+offset, len - offset);
    dest1[offset + 1] = '\0';
    dest1[len - offset + 1] = '\0';

    return true;
}

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

int strwords(char s[static 1]) {
    bool isword = false;
    bool prevWhite = true;
    int count = 0;
    while (*s) {
        if (*s == ' ' || *s == '\n' || *s == '\t') {
            prevWhite = true;
        } else if (prevWhite) {
            isword = true;
            prevWhite = false;
        }
        if (isword) {
            count += 1;
            isword = false;
        }
        s += 1;
    }
    return count;
}
