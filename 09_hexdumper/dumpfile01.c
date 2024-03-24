#include <stdio.h>
#include <stdlib.h>

void line_out(int offset, size_t len, unsigned char const data[len]) {
    printf("%05x ", offset);

    for (int i = 0; i < len; i += 1) {
        printf(" %02x", data[i]);
        if ((i + 1) % 8 == 0) {
            putchar(' ');
        }
    }

    putchar(' ');

    for (int i = 0; i < len; i += 1) {
        if (' ' <= data[i] && data[i] <= '~') {
            putchar(data[i]);
        } else {
            putchar(' ');
        }
    }

    putchar('\n');
}


#define BUFF_LEN 16

int main(int argc, char const*const argv[argc]) {
    if (argc < 2) {
        fprintf(stderr, "Format: dumfile filename\n");
        exit(1);
    }
    char const*const filename = argv[1];

    FILE* fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Unable to open file '%s'\n", filename);
        exit(1);
    }

    int i = 0;
    int offset = 0;
    unsigned char buff[BUFF_LEN];
    while (!feof(fp)) {
        char ch = fgetc(fp);
        if (ch == EOF) {
            if (0 < i) {
                line_out(offset, i, buff);
            }
            break;
        }
        buff[i] = ch;
        i += 1;
        if (i == BUFF_LEN) {
            line_out(offset, BUFF_LEN, buff);
            offset += BUFF_LEN;
            i = 0;
        }
    }

    fclose(fp);
    return 0;
}
