#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BALLS 68
#define DRAW 5

int main() {
    srand((unsigned)time((void*)0));

    printf("Drawing %d numbers from %d balls:\n", DRAW, BALLS);
    int r = rand() % BALLS + 1;
    for (int i = 0; i < DRAW - 1; i += 1) {
        printf("%02d ", r);
        r = rand() % BALLS + 1;
    }
    printf("%02d\n", r);

    return 0;
}
