#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* strinsert(
    size_t offset,
    char src[static 1],
    char ins[static 1]
) {
    if (offset < 0) {
        return (void*)0;
    }
    size_t size = offset + strlen(ins);
    char* new = malloc(sizeof(char[size+1]));
    if (!new) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    memcpy(new, src, offset);
    new[offset] = '\0';
    strcat(new, ins);
    return new;
}

void strinsert2(
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

int main() {
    char org[] = "Well, this is another mess!";
    char* n = strinsert(22, org, "fine!");
    if (!n) {
        return 0;
    }
    char dest[32];
    strinsert2(22, org, "fine!", dest);
    printf("%s\n", n);
    printf("%s\n", dest);
    free(n);
    return 0;
}
