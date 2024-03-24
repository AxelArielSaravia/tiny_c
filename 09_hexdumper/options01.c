#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *const argv[argc]) {
    int r = getopt(argc, argv, "abc");
    while (r != -1) {
        switch (r) {
            case 'a':
                puts("alfa option set");
                break;
            case 'b':
                puts("bravo option set");
                break;
            case 'c':
                puts("charlie");
                break;
            case '?':
                printf("Switc '%c' is invalid\n", optopt);
                break;
            default:
                puts("Unknown option");
        }

        r = getopt(argc, argv, "abc");
    }
    return 0;
}
