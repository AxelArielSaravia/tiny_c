#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSW_LEN 10

int main() {
    srand(time((void*)0));

    for (int k = 0; k < PASSW_LEN; k += 1) {
        char ch = rand() & ('~' - '!' + 1);
        putchar(ch + '!');
    }
    putchar('\n');
    return 0;
}
