#include <stdio.h>
#include <time.h>

#define HEADER "Sun Mon Tue Wed Thu Fri Sat\n"

int main() {
    time_t now = time((void*)0);
    struct tm* date = localtime(&now);

    int curr_day = date->tm_mday;

    //sunday
    int day = date->tm_mday - date->tm_wday;

    printf(HEADER);
    printf("%2d ", day);
    day += 1;

    for (int i = 1; i < 7; i += 1) {
        if (day == curr_day) {
            printf("[%2d]", day);
        } else {
            printf(" %2d ", day);
        }
        day += 1;
    }
    putchar('\n');

    return 0;
}
