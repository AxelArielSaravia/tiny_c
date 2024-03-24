#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SYMBOLS_LEN 8
char const Symbols[SYMBOLS_LEN] = "!@#$%*_-";

typedef enum Case Case;
enum Case {
    Case_Upper,
    Case_Lower,
    Case_Num,
    Case_Sym,
    Case_Len
};

unsigned Case_Chars[Case_Len] = {
    [Case_Upper] = 1,
    [Case_Lower] = 6,
    [Case_Num]   = 1,
    [Case_Sym]   = 2,
};

typedef char Case_Action(void);
Case_Action uppercase;
Case_Action lowercase;
Case_Action numbercase;
Case_Action symbolcase;

Case_Action* const Case_Actions[Case_Len] = {
    [Case_Upper] = &uppercase,
    [Case_Lower] = &lowercase,
    [Case_Num]   = &numbercase,
    [Case_Sym]   = &symbolcase,
};

char const*const Case_Args[Case_Len] = {
    [Case_Upper] = "-u",
    [Case_Lower] = "-l",
    [Case_Num]   = "-n",
    [Case_Sym]   = "-s",
};

void help_message(void) {
    printf("Random pasword generator\n");
    printf("Example: ./randomp04.bin [-u] [-l] [-n] [-s]\n\n");
    printf("    -u[number]  number of upper case characters, must be number greater than 0\n");
    printf("    -l[number]  number of lower case characters, must be number greater than 0\n");
    printf("    -n[number]  number of number characters, must be number greater than 0\n");
    printf("    -s[number]  number of symbols characters, must be number greater than 0\n\n");
}

int main(int argc, char const*const argv[argc]) {
    srand(time((void*)0));
    int disposable = Case_Len;
    Case cases[Case_Len] = {Case_Upper, Case_Lower, Case_Num, Case_Sym};

    if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        help_message();
        return 0;
    }
    if (1 < argc) {
        _Bool select_arg = 0;
        for (int k = 1; k < argc; k += 1) {
            char const*const arg = argv[k];
            for (int j = 0; j < disposable; j += 1) {
                Case c = cases[j];
                if (strncmp(arg, Case_Args[c], 2) == 0) {
                    int v = atoi(arg+2);
                    if (v < 1) {
                        fprintf(stderr, "The values must be positive integer\n");
                        exit(-1);
                    }
                    Case_Chars[c] = v;
                    select_arg = 1;
                    disposable -= 1;
                    if (j < disposable) {
                        Case temp = cases[disposable];
                        cases[disposable] = cases[j];
                        cases[j] = temp;
                    }
                }
            }
            if (!select_arg) {
                fprintf(stderr, "Invalid argument\n");
                exit(-1);
            }
            select_arg = 0;
        }
        disposable = Case_Len;
    }

    int passw_len = 0;
    for (int k = Case_Upper; k < Case_Len; k += 1) {
        passw_len += Case_Chars[k];
    }


    int count[Case_Len] = {0};

    char buff[passw_len + 1];
    buff[passw_len] = '\0';
    int n = 0;
    while (n < passw_len) {
        int r = rand() % disposable;
        int s = cases[r];
        buff[n] = Case_Actions[s]();
        count[s] += 1;
        n += 1;
        if (count[s] == Case_Chars[s] && disposable > 1) {
            disposable -= 1;
            if (r < disposable) {
                int temp = cases[disposable];
                cases[disposable] = s;
                cases[r] = temp;
            }
        }
    }
    printf("%s\n", buff);
    return 0;
}

char uppercase(void) {
    return (rand() % ('Z' - 'A' + 1)) + 'A';
}

char lowercase(void) {
    return (rand() % ('z' - 'a' + 1)) + 'a';
}

char numbercase(void) {
    return (rand() % ('9' - '0' + 1)) + '0';
}

char symbolcase(void) {
    int i = rand() % SYMBOLS_LEN;
    return Symbols[i];
}
