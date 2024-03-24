#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VOCABULARY_LEN 12
char const*const vocabulary[VOCABULARY_LEN] = {
    "orange",
    "grape",
    "apple",
    "banana",
    "coffee",
    "tea",
    "juice",
    "beverage",
    "happy",
    "grumpy",
    "bashful",
    "sleepy"
};

char const* add_word(void) {
    int r = rand() % VOCABULARY_LEN;
    return vocabulary[r];
}
int main() {
    srand(time((void*)0));
    for (int i = 0; i < 3; i += 1) {
        printf("%s ", add_word());
    }
    putchar('\n');
    return 0;
}
