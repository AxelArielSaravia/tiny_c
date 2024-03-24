#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER_CHARS 1
#define LOWER_CHARS 6
#define NUM_CHARS   1
#define SYM_CHARS   2

#define PASSW_LEN (UPPER_CHARS+LOWER_CHARS+NUM_CHARS+SYM_CHARS)

#define SYMBOLS_LEN 8
char const Symbols[SYMBOLS_LEN] = "!@#$%*_-";

char uppercase() {
    return (rand() % ('Z' - 'A' + 1)) + 'A';
}

char lowercase() {
    return (rand() % ('z' - 'a' + 1)) + 'a';
}

char numbercase() {
    return (rand() % ('9' - '0' + 1)) + '0';
}

char symbolcase() {
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

int main() {
    char password[PASSW_LEN+1];
    password[PASSW_LEN] = '\0';
    srand(time((void*)0));
    int x = 0;
    while (x < UPPER_CHARS) {
        password[x] = uppercase();
        x += 1;
    }
    while (x < UPPER_CHARS + LOWER_CHARS) {
        password[x] = lowercase();
        x += 1;
    }
    while (x < UPPER_CHARS + LOWER_CHARS + NUM_CHARS) {
        password[x] = numbercase();
        x += 1;
    }
    while (x < UPPER_CHARS + LOWER_CHARS + NUM_CHARS + SYM_CHARS) {
        password[x] = symbolcase();
        x += 1;
    }
    scramble(PASSW_LEN, password);
    printf("%s\n", password);
    return 0;
}
