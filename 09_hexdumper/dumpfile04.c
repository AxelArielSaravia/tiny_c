#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFF_SIZE 16

#define OPTIONS "aoh"
#define ABBR 1
#define OCT 2

int options = 0;

char const*const output_format[] = {
    " %02x",
    " %03o"
};

char const*const offset_format[] = {
    "%05x ",
    "%05o "
};

char const*const space_format[] = {
    "   ",
    "    "
};

_Bool is_abbr() {
    return (options & ABBR) == ABBR;
};

_Bool is_oct() {
    return (options & OCT) == OCT;
};

void help(void) {
    puts("dumpfile - output a file's raw data");
    puts("Usage: dumpfile filename [options]\n");
    puts("Options:");
    puts("\t -a\t abbrevoated output");
    puts("\t -o\t output octal instead of hex");
    puts("\t -h\t display this text");
    exit(1);
}

void set_options(int const argc, char*const argv[argc]) {
    int r = getopt(argc, argv, OPTIONS);
    while (r != -1) {
        switch (r) {
            case 'a':
                options |= ABBR;
                break;
            case 'o':
                options |= OCT;
                break;
            case 'h':
                help();
                break;
            case '?':
                printf("Switch '%c' is invalid\n", optopt);
                break;
            default:
                puts("Unknown option");
        }
        r = getopt(argc, argv, OPTIONS);
    }
}

void abbr_line_out(
    size_t const data_len,
    unsigned char const data[data_len]
) {
    char const*const format = output_format[is_oct()];
    for (int i = 0; i < data_len; i += 1) {
        printf(format, data[i]);
    }
    putchar('\n');
}

void normal_line_out(
    int const offset,
    size_t const data_len,
    unsigned char const data[data_len]
) {
    int format = is_oct();
    //offline
    printf(offset_format[format], offset);

    //content
    for (int i = 0; i < data_len; i += 1) {
        printf(output_format[format], data[i]);
        if ((i + 1) % 8 == 0) {
            putchar(' ');
        }
    }
    putchar(' ');

    //align ascii
    if (data_len < BUFF_SIZE) {
        for (int i = data_len; i < BUFF_SIZE; i += 1) {
            printf(space_format[format]);
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

void line_out(
    int const offset,
    size_t const data_len,
    unsigned char const data[data_len]
) {
    if (is_abbr()) {
        abbr_line_out(data_len, data);
    } else {
        normal_line_out(offset, data_len, data);
    }
}

int main(int const argc, char *const argv[argc]) {
    if (argc < 2) {
        puts("Format: dumpfile filename [options]");
        exit(1);
    }

    char const*const filename = argv[1];

    if (strcmp(filename, "-h") == 0) {
        help();
    }
    set_options(argc, argv);

    FILE* fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "File ERROR: Unable to open '%s'\n", filename);
        exit(1);
    }

    int i = 0;
    int offset = 0;
    unsigned char buff[BUFF_SIZE];

    while (!feof(fp)) {
        char const ch = fgetc(fp);
        if (ch == EOF) {
            if (0 < i) {
                line_out(offset, i, buff);
            }
            break;
        }

        buff[i] = ch;
        i += 1;
        if (i == BUFF_SIZE) {
            line_out(offset, BUFF_SIZE, buff);
            offset += BUFF_SIZE;
            i = 0;
        }
    }

    fclose(fp);

    return 0;
}
