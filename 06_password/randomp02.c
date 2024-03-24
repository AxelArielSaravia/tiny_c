#include <stdio.h>
#include <stdlib.h>
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

unsigned const Case_Chars[Case_Len] = {
    [Case_Upper]    = 1,
    [Case_Lower]    = 6,
    [Case_Num]      = 1,
    [Case_Sym]      = 2,
};

typedef char Case_Action(void);
Case_Action uppercase;
Case_Action lowercase;
Case_Action numbercase;
Case_Action symbolcase;

Case_Action* Case_Actions[Case_Len] = {
    [Case_Upper]    = &uppercase,
    [Case_Lower]    = &lowercase,
    [Case_Num]      = &numbercase,
    [Case_Sym]      = &symbolcase,
};

int main() {
    srand(time((void*)0));

    int passw_len = 0;
    for (int k = Case_Upper; k < Case_Len; k += 1) {
        passw_len += Case_Chars[k];
    }

    int count[Case_Len] = {0};
    int disposable = Case_Len;
    Case cases[Case_Len] = {Case_Upper, Case_Lower, Case_Num, Case_Sym};

    int n = 0;
    while (n < passw_len) {
        int r = rand() % disposable;
        int s = cases[r];
        putchar(Case_Actions[s]());
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
    putchar('\n');
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
