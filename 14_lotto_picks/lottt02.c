#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BALLS 68
#define DRAWS 5

int main() {
    srand((unsigned)time((void*)0));

    int winners[DRAWS];
    for (int i = 0; i < DRAWS; i += 1) {
        int r = rand() % BALLS + 1;
        int k = 0;
        while (k < i) {
            if (winners[k] == r) {
                k = 0;
                r = rand() % BALLS + 1;
            } else {
                k += 1;
            }
        }
        winners[i] = r;
    }

    printf("Drawing %d numbers from %d balls:\n", DRAWS, BALLS);

    for (int i = 0; i < DRAWS-1; i += 1) {
        printf("%02d ", winners[i]);
    }
    printf("%02d\n", winners[DRAWS - 1]);

    return 0;
}

