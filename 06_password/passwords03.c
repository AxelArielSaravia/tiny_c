#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Term Term;
struct Term {
    int items;
    char const** list_base;
};

#define SYMBOLS_LEN 8
char const Symbols[SYMBOLS_LEN] = "!@#$%*_-";

typedef enum Case Case;
enum Case {
    Case_Noun,
    Case_Adj,
    Case_Verb,
    Case_Num,
    Case_Sym,
    Case_Len
};

unsigned const Case_Values[Case_Len] = {
    [Case_Noun] = 1,
    [Case_Adj]  = 1,
    [Case_Verb] = 1,
    [Case_Num]  = 1,
    [Case_Sym]  = 1
};

#define BUFF_SIZE 32
Term build_vocabulary(FILE fp[static 1]) {
    char buff[BUFF_SIZE];
    char const** list_base = calloc(100, sizeof(char*));
    if (!list_base) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    char* r = 0;
    char* entry = 0;
    int items = 0;
    while (!feof(fp)) {
        r = fgets(buff, BUFF_SIZE, fp);
        if (!r) {
            break;
        }
        entry = calloc(strlen(buff) + 1, sizeof(char));
        if (!entry) {
            fprintf(stderr, "Unable to allocate memory\n");
            exit(1);
        }
        strcpy(entry, buff);

        r = entry;
        int w_len = 0;
        char c = r[w_len];
        while (c) {
            if (c == '\n') {
                r[w_len] = '\0';
                break;
            }
            w_len += 1;
            c = r[w_len];
        }

        int ri = rand() % w_len;
        if (97 <= r[ri] && r[ri] <= 122) {
            r[ri] -= 32;
        }

        list_base[items] = entry;
        items += 1;
        if (items % 100 == 0) {
            list_base = realloc(list_base, sizeof(char*) * (items + 100));
            if (!list_base) {
                fprintf(stderr, "Unable to allocate memory\n");
                exit(1);
            }
        }
    }
    return (Term){items, list_base};
}

char const* get_word(Term t) {
    int word = rand() % t.items;
    return t.list_base[word];
}

char* get_number(char n[2]) {
    n[0] = (rand() % ('9' - '0' + 1)) + '0';
    return n;
}

char* get_symbol(char s[2]) {
    int r = rand() % SYMBOLS_LEN;
    s[0] = Symbols[r];
    return s;
}

int main() {
    FILE* noun_fp = fopen("nouns.txt", "r");
    FILE* verb_fp = fopen("verbs.txt", "r");
    FILE* adjective_fp = fopen("adjectives.txt", "r");

    if (!noun_fp || !verb_fp || !adjective_fp) {
        fprintf(stderr, "Unable to read file");
        exit(1);
    }
    Term noun = build_vocabulary(noun_fp);
    Term verb = build_vocabulary(verb_fp);
    Term adjective = build_vocabulary(adjective_fp);

    fclose(noun_fp);
    fclose(verb_fp);
    fclose(adjective_fp);

    srand(time((void*)0));

    char password[32] = {[0] = '\0'};
    char characters[2] = {[1] = '\0'};

    Case cases[Case_Len] = {
        Case_Noun,
        Case_Adj,
        Case_Verb,
        Case_Num,
        Case_Sym
    };
    int count[Case_Len] = {0};
    int disposable = Case_Len;
    int len = 0;
    for (int i = 0; i < Case_Len; i += 1) {
        len += Case_Values[i];
    }
    int n = 0;
    while (n < len) {
        int r = rand() % disposable;
        int s = cases[r];
        if (s == Case_Noun) {
            strcat(password, get_word(noun));
        } else if (s == Case_Adj) {
            strcat(password, get_word(adjective));
        } else if (s == Case_Verb) {
            strcat(password, get_word(verb));
        } else if (s == Case_Num) {
            strcat(password, get_number(characters));
        } else {
            strcat(password, get_symbol(characters));
        }
        count[s] += 1;
        n += 1;
        if (count[s] == Case_Values[s] && disposable > 1) {
            disposable -= 1;
            if (r < disposable) {
                int temp = cases[disposable];
                cases[disposable] = s;
                cases[r] = temp;
            }
        }
    }

    printf("%s\n", password);
    return 0;
}
