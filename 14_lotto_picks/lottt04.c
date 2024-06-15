#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BALLS 68
#define DRAWS 5

int main() {
    srand((unsigned)time((void*)0));

    _Bool numbers[BALLS] = {0};
    int winners[DRAWS];
    int i = 0;
    while (i < DRAWS) {
        int r = rand() % BALLS;
        if (!numbers[r]) {
            numbers[r] = (_Bool)1;
            winners[i] = r + 1;
            i += 1;
        }
    }

    printf("Drawing %d numbers from %d balls:\n", DRAWS, BALLS);
    for (int i = 0; i < DRAWS - 1; i += 1) {
        printf("%02d - ", winners[i]);
    }
    printf("%02d\n", winners[DRAWS - 1]);

    return 0;
}
