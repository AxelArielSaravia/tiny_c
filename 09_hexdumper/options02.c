#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *const argv[argc]) {
    _Bool alfa = (_Bool)0;
    _Bool bravo = (_Bool)0;
    _Bool charlie = (_Bool)0;

    int r = getopt(argc, argv, "abc");

    while (r != -1) {
        if (r == 'a') {
            alfa = (_Bool)1;
        } else if (r == 'b') {
            bravo = (_Bool)1;
        } else if (r == 'c') {
            charlie = (_Bool)1;
        }
        r = getopt(argc, argv, "abc");
    }

    if (alfa + bravo + charlie == 0) {
        puts("No options set");
    } else {
        if (alfa) {
            puts("alfa option set");
        }
        if (bravo) {
            puts("bravo option set");
        }
        if (charlie) {
            puts("charlie option set");
        }
    }

    return 0;
}
