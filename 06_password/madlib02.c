#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFF_SIZE 32

typedef struct Term Term;
struct Term {
    int items;
    char const** list_base;
};

Term build_vocabulary(FILE fp[static 1]) {
    char buff[BUFF_SIZE];

    char const** list_base = malloc(sizeof(char*) * 100);
    if (!list_base) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    char* r;
    char* entry;
    int items = 0;
    while (!feof(fp)) {
        r = fgets(buff, BUFF_SIZE, fp);
        if (!r) {
            break;
        }
        entry = malloc(sizeof(char) * (strlen(buff) + 1));
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
    return (Term){
        .items = items,
        .list_base = list_base,
    };
}

char const* add_word(Term t) {
    int word = rand() % t.items;
    return t.list_base[word];
}

int main() {
    FILE* fp_noun = fopen("nouns.txt", "r");
    FILE* fp_verb = fopen("verbs.txt", "r");
    FILE* fp_adjective = fopen("adjectives.txt", "r");

    if (!fp_noun || !fp_verb || !fp_adjective) {
        fprintf(stderr, "Unable to open files\n");
        exit(1);
    }

    Term noun = build_vocabulary(fp_noun);
    Term verb = build_vocabulary(fp_verb);
    Term adjective = build_vocabulary(fp_adjective);
    fclose(fp_noun);
    fclose(fp_verb);
    fclose(fp_adjective);

    srand((unsigned)time((void*)0));
    printf(
        "Will you please take the %s %s ",
        add_word(adjective),
        add_word(noun)
    );
    printf(
        "and %s the %s?\n",
        add_word(verb),
        add_word(noun)
    );

    return 0;
}
