#include <stdio.h>
#include <stdlib.h>


#define CELLS 5
int main() {
    for (int y = 0; y < CELLS; y += 1) {
        int r = rand();
        for (int x = 0; x < CELLS -1; x += 1) {
            printf("%10d ", r);
            r = rand();
        }
        printf("%10d\n", r);
    }
    return 0;
}
