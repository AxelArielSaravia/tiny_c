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
        while (*r) {
            if (*r == '\n') {
                *r = '\0';
                break;
            }
            r += 1;
        }
        list_base[items] = entry;
        items += 1;
        if (items % 100 == 0) {
            list_base = realloc(list_base, sizeof(char*) * (items + 100));
            if (!list_base) {
                fprintf(stderr, "Unable to reallocate memory\n");
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

char* get_symbol(char s[2]) {
    int r = rand() % SYMBOLS_LEN;
    s[0] = Symbols[r];
    return s;
}

char* get_number(char n[2]) {
    n[0] = (rand() % ('9' - '0' + 1)) + '0';
    return n;
}

int main() {
    FILE* noun_fp = fopen("nouns.txt", "r");
    FILE* verb_fp = fopen("verbs.txt", "r");
    FILE* adjective_fp = fopen("adjectives.txt", "r");

    if (!noun_fp || !verb_fp || !adjective_fp) {
        fprintf(stderr, "Unable to open files\n");
        exit(1);
    }

    Term noun = build_vocabulary(noun_fp);
    Term verb = build_vocabulary(verb_fp);
    Term adjective = build_vocabulary(adjective_fp);

    fclose(noun_fp);
    fclose(verb_fp);
    fclose(adjective_fp);

    srand(time((void*)0));

    char password[32];
    char characters[2] = {[1] = '\0'};

    strcpy(password, get_word(noun));
    strcat(password, get_number(characters));
    strcat(password, get_word(verb));
    strcat(password, get_symbol(characters));
    strcat(password, get_word(adjective));

    printf("%s\n", password);

    return 0;
}
