#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SYMBOLS_LEN 8
char const Symbols[SYMBOLS_LEN] = "!@#$%*_-";

#define VOCABULARY_LEN 12
char const*const Vocabulary[VOCABULARY_LEN] = {
    "Orange",
    "Grape",
    "Apple",
    "Banana",
    "coffe",
    "tea",
    "juice",
    "beverage",
    "happY",
    "grumpY",
    "bashfuL",
    "sleepY",
};

char* get_number(char n[2]) {
    n[0] = (rand() % ('9' - '0' + 1)) + '0';
    return n;
}

char* get_symbol(char s[2]) {
    int r = rand() % SYMBOLS_LEN;
    s[0] = Symbols[r];
    return s;
}

char const* add_word(void) {
    int r = rand() % VOCABULARY_LEN;
    return Vocabulary[r];
}

int main(int argc, char const* argv[argc]) {
    char password[32] = {[0] = '\0'};
    static char characters[2] = {[1] = '\0'};
    srand(time((void*)0));

    strcpy(password, add_word());
    strcat(password, get_number(characters));
    strcat(password, add_word());
    strcat(password, get_symbol(characters));
    strcat(password, add_word());

    printf("%s\n", password);

    return 0;
}
