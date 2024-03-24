/* mystr library header file */
/* Axel Ariel Saravia, axelarielsaravia@gmail.com */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define mystr_version "0.1.0"

typedef enum bool bool;
enum bool {
    false,
    true
};

void left(size_t const len, char dest[static 1], char src[static 1]);
void right(size_t len, char dest[static 1], char src[static 1]);
void mid(size_t len, char dest[static 1], char src[static 1], size_t offset);

void strcap(char str[static 1]);

void strinsert(
    size_t offset,
    char src[static 1],
    char ins[static 1],
    char dest[static 1]
);

void strupper(char s[static 1]);
void strlower(char s[static 1]);

void strrev(char s[static 1]);

bool strsplit(
    size_t offset,
    char src[static 1],
    char dest1[static 1],
    char dest2[static 1]
);

void strtabs(char const s[static 1], int tab);

int strwords(char s[static 1]);
