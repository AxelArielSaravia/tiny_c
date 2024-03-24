#include <stdio.h>
#include <stdlib.h>
#include <string.h>


_Bool strsplit(
    size_t offset,
    char src[static 1],
    char dest1[static 1],
    char dest2[static 1]
) {
    size_t len = strlen(src);
    if (len < offset) {
        return 0;
    }
    memcpy(dest1, src, offset);
    memcpy(dest2, src+offset, len - offset);
    dest1[offset + 1] = '\0';
    dest1[len - offset + 1] = '\0';

    return 1;
}

int main() {
    char str[] = "Some String adasd mmake asdnne mm";
    char buff1[32];
    char buff2[32];
    strsplit(16, str, buff1, buff2);
    printf("%s\n", str);
    printf("%s\n", buff1);
    printf("%s\n", buff2);
    return 0;
}
