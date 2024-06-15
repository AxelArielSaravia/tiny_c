#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BALLS 68
#define DRAWS 5

void lotto(int match[DRAWS]) {
    _Bool numbers[BALLS] = {0};
    int i = 0;
    while (i < DRAWS) {
        int r = rand() % BALLS + 1;
        if (!numbers[r]) {
            numbers[r] = (_Bool)1;
            match[i] = r;
            i += 1;
        }
    }
}

int main() {
    srand((unsigned)time((void*)0));

    int match[DRAWS];
    printf("Trying to match: ");
    lotto(match);

    for (int i = 0; i < DRAWS - 1; i += 1) {
        printf("%02d - ", match[i] + 1);
    }
    printf("%02d\n", match[DRAWS - 1] + 1);

    return 0;
}
