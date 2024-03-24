#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#define FILE_NAME "alphabeta.wtxt"
#define BUFF_LEN 64

int main() {
    setlocale(LC_CTYPE, "en_US.utf8");

    FILE* fp = fopen(FILE_NAME, "r");
    if (!fp) {
        fprintf(stderr, "Unable to open '%s'\n", FILE_NAME);
        exit(1);
    }

    wprintf(L"Reading from %s:\n", FILE_NAME);

    wint_t ch = fgetwc(fp);
    while (ch != WEOF) {
        putwchar(ch);
        ch = fgetwc(fp);
    }
    putwchar('\n');

    fclose(fp);

    return 0;
}
