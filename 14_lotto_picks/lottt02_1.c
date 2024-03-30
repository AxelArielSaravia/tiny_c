#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_BALLS 68
#define DRAWS 5

void init_balls(int balls[TOTAL_BALLS]) {
    for (int i = 0; i < TOTAL_BALLS;i += 1) {
        balls[i]= i + 1;
    }
}

int main() {
    int balls[TOTAL_BALLS];
    init_balls(balls);

    srand((unsigned)time((void*)0));
    
    int winners[DRAWS];
    int len = TOTAL_BALLS;


    for (int i = 0; i < DRAWS; i += 1) {
        int r = rand() % len;
        winners[i] = balls[r];
        balls[r] = balls[len - 1];
        len -= 1;
    }
    printf("Drawing %d numbers from %d balls:\n", DRAWS, TOTAL_BALLS);

    for (int i = 0; i < DRAWS-1; i += 1) {
        printf("%02d ", winners[i]);
    }
    printf("%02d\n", winners[DRAWS - 1]);

    return 0;
}

