#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>

#define alpha    0x391
#define omega    0x3a9
#define no_sigma 0x3a2

#define FILE_NAME "alphabeta.wtxt"
int main() {
    setlocale(LC_CTYPE, "en_US.utf8");

    FILE* fp = fopen(FILE_NAME, "w");
    if (!fp) {
        fprintf(stderr, "unable to open '%s'\n", FILE_NAME);
        exit(1);
    }

    wprintf(L"Writing the Greek alphabet...\n");
    for (int i = alpha; i <= omega; i += 1) {
        if (i != no_sigma) {
            fputwc(i, fp);
            fputwc(i, stdout);
        }
    }
    fputwc('\0', fp);
    fclose(fp);
    wprintf(L"\nDone\n");
    return 0;
}
