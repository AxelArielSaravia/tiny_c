#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#define CYR_FST 0x0410
#define CYR_LST 0x042f

#define FILE_NAME "alphabetc.wtxt"

int main(int argc, char const*const argv[argc]) {
    if (argc < 3) {
        setlocale(LC_CTYPE, "es_US.utf8");
        char opt;
        if (argc == 2 && strcmp(argv[1], "-r") == 0) {
            opt = 'r';
        } else {
            opt = 'w';
        }
        FILE* fp = fopen(FILE_NAME, &opt);
        if (!fp) {
            fprintf(stderr, "Unable to open %s\n", FILE_NAME);
            exit(1);
        }
        if (opt == 'w') {
            wprintf(L"Writing the Cyrillic Alphabet\n");
            for (int i = CYR_FST; i <= CYR_LST; i += 1) {
                fputwc(i, fp);
                fputwc(i, stdout);
            }
            fputwc('\0', fp);
            wprintf(L"\nDONE\n");
        } else {
            wchar_t ch = fgetwc(fp);
            while (ch != WEOF) {
                fputwc(ch, stdout);
                ch = fgetwc(fp);
            }
            fputwc('\n', stdout);
        }
        fclose(fp);
    } else {
        fprintf(stderr,"Options must be set -r[ead] or -w[rite]\n");
    }
    return 0;
}
