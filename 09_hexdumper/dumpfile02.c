#include <stdio.h>
#include <stdlib.h>

void line_out(
    int const offset,
    size_t const content_len,
    size_t const data_len,
    unsigned char const data[data_len]
) {
    //offset
    printf("%05x ", offset);

    //hex content
    for (int i = 0; i < data_len; i += 1) {
        printf(" %02x", data[i]);
        if ((i + 1) % 8 == 0) {
            putchar(' ');
        }
    }
    putchar(' ');

    //align ascii
    if (data_len < content_len) {
        for (int i = data_len; i < content_len; i += 1) {
            printf("   ");
            if ((i + 1) % 8 == 0) {
                putchar(' ');
            }
        }
    }

    //ascii
    for (int i = 0; i < data_len; i += 1) {
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
        fprintf(stderr, "Argument Not Found ERROR: You need to give a filename");
        exit(1);
    }
    char const*const filename = argv[1];

    FILE* fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "File ERROR: Unable to open '%s'\n", filename);
        exit(1);
    }

    int i = 0;
    int offset = 0;
    unsigned char buff[BUFF_LEN];

    while (!feof(fp)) {
        char ch = fgetc(fp);
        if (ch == EOF) {
            if (0 < i) {
                line_out(offset, BUFF_LEN, i, buff);
            }
            break;
        }
        buff[i] = ch;
        i += 1;
        if (i == BUFF_LEN) {
            line_out(offset, BUFF_LEN, BUFF_LEN, buff);
            offset += BUFF_LEN;
            i = 0;
        }
    }

    fclose(fp);
    return 0;
}
