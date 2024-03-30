#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELLS 5
int main() {
    srand((unsigned)time((void*)0));

    for (int y = 0; y < CELLS; y += 1) {
        int r = rand() % 100 + 1;
        for (int x = 0; x < CELLS; x += 1) {
            printf("%3d ", r);
            r = rand() % 100 + 1;
        }
        printf("%3d\n", r);
    }

    return 0;
}

