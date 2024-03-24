#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DEFAULT_UPPER_CHARS 1
#define DEFAULT_LOWER_CHARS 6
#define DEFAULT_NUM_CHARS   1
#define DEFAULT_SYM_CHARS   2

#define DEFAULT_PASSW_LEN (\
    DEFAULT_UPPER_CHARS\
    + DEFAULT_LOWER_CHARS\
    + DEFAULT_NUM_CHARS\
    + DEFAULT_SYM_CHARS\
)

#define SYMBOLS_LEN 8
char const Symbols[SYMBOLS_LEN] = "!@#$%*_-";

char get_upperchar(void) {
    return (rand() % ('Z' - 'A' + 1)) + 'A';
}

char get_lowerchar(void) {
    return (rand() % ('z' - 'a' + 1)) + 'a';
}

char get_number(void) {
    return (rand() % ('9' - '0' + 1)) + '0';
}

char get_symbol(void) {
    int r = rand() % SYMBOLS_LEN;
    return Symbols[r];
}

void scramble(size_t size, char arr[size]) {
    for (size_t i = size - 1; 0 < i; i -= 1) {
        int r = rand() % i;
        char temp = arr[r];
        arr[r] = arr[i];
        arr[i] = temp;
    }
}

int main(int argc, char const* argv[argc]) {
    int upper_chars = DEFAULT_UPPER_CHARS;
    int lower_chars = DEFAULT_LOWER_CHARS;
    int num_chars = DEFAULT_NUM_CHARS;
    int sym_chars = DEFAULT_SYM_CHARS;
    int passw_len = DEFAULT_PASSW_LEN;
    if (1 < argc) {
        for (int i = 1; i < argc; i += 1) {
            char const* arg = argv[i];
            if (strncmp(arg, "-u", 2) == 0) {
                upper_chars = atoi(arg+2);
                if (upper_chars < 1) {
                    fprintf(stderr, "The values must be positive integer\n");
                    exit(-1);
                }
            } else if (strncmp(arg, "-l", 2) == 0) {
                lower_chars = atoi(arg+2);
                if (lower_chars < 1) {
                    fprintf(stderr, "The values must be positive integer\n");
                    exit(-1);
                }
            } else if (strncmp(arg, "-n", 2) == 0) {
                num_chars = atoi(arg+2);
                if (num_chars < 1) {
                    fprintf(stderr, "The values must be positive integer\n");
                    exit(-1);
                }
            } else if (strncmp(arg, "-s", 2) == 0) {
                sym_chars = atoi(arg+2);
                if (sym_chars < 1) {
                    fprintf(stderr, "The values must be positive integer\n");
                    exit(-1);
                }
            } else {
                fprintf(stderr, "Invalid argument. '%s' is not known\n", arg);
                exit(-1);
            }
        }
        passw_len = upper_chars + lower_chars + num_chars + sym_chars;
    }
    char password[passw_len+1];
    password[passw_len] = '\0';

    srand(time((void*)0));
    int x = 0;
    while (x < upper_chars) {
        password[x] = get_upperchar();
        x += 1;
    }
    while (x < upper_chars + lower_chars) {
        password[x] = get_lowerchar();
        x += 1;
    }
    while (x < upper_chars + lower_chars + num_chars) {
        password[x] = get_number();
        x += 1;
    }
    while (x < upper_chars + lower_chars + num_chars + sym_chars) {
        password[x] = get_symbol();
        x += 1;
    }
    scramble(passw_len, password);
    printf("%s\n", password);
    return 0;
}
