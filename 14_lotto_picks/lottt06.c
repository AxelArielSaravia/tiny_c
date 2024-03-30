#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BALLS 68
#define DRAWS 5

void lotto(int match[DRAWS]) {
    _Bool numbers[BALLS] = {0};
    int i = 0;
    while (i < DRAWS) {
        int r = rand() % BALLS;
        if (!numbers[r]) {
            numbers[r] = (_Bool)1;
            match[i] = r + 1;
            i += 1;
        }
    }
}

void print_draws(int nums[DRAWS]) {
    for (int i = 0; i < DRAWS - 1; i += 1) {
        printf("%02d - ", nums[i]);
    }
    printf("%02d\n", nums[DRAWS - 1]);
}

int main() {
    srand((unsigned)time((void*)0));

    int match[DRAWS];
    int guess[DRAWS];
    lotto(match);
    lotto(guess);

    printf("Trying to match: ");
    print_draws(match);
    printf("     Your guess: ");
    print_draws(guess);

    return 0;
}
