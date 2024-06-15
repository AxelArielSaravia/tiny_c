#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned)time((void*)0));
    int r = rand() % 2;
    if (r) {
        fprintf(stderr, "Welp, this program screwed [CA]up!\n");
        return EXIT_FAILURE;
    } else {
        printf("Every went tod ucky!\n");
        return EXIT_SUCCESS;
    }
}
