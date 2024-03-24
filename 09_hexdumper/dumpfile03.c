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
        for (int i = data_len; i < content_len;i += 1) {
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
#define FILENAME_LEN 256
int main(int const argc, char const*const argv[argc]) {
    char filename_buff[FILENAME_LEN];
    char* filename = 0;
    if (argc < 2) {
        printf("Filename: ");
        filename = fgets(filename_buff, FILENAME_LEN, stdin);
        if (!filename || filename_buff[0] == '\n') {
            exit(1);
        }
        int i = 1;
        while (1) {
            if (i == FILENAME_LEN) {
                exit(1);
            }
            if (filename_buff[i] == '\n') {
                filename_buff[i] = '\0';
                break;
            }
            i += 1;
        }
    } else {
        filename = (char*)argv[1];
    }

    FILE* fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "File ERROR: Unable to open '%s'\n", filename);
        exit(1);
    }

    int i = 0;
    int offset = 0;
    unsigned char buff[BUFF_LEN];
    while (!feof(fp)) {
        char const ch = fgetc(fp);
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
