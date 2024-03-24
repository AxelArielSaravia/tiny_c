#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#define FILE_NAME "alphabeta.wtxt"
#define BUFF_LEN 64
int main() {
    setlocale(LC_CTYPE, "en_US.utf8");

    wchar_t buff[BUFF_LEN];
    FILE* fp = fopen(FILE_NAME, "r");
    if (!fp) {
        fprintf(stderr, "unable to open '%s'\n", FILE_NAME);
        exit(1);
    }

    wprintf(L"Reading from %s:\n", FILE_NAME);
    fgetws(buff, BUFF_LEN, fp);
    wprintf(L"%ls\n", buff);

    fclose(fp);

    return 0;
}
