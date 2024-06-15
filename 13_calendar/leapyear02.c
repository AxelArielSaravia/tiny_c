#include <stdio.h>

_Bool is_leap_year(int year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

int main() {
    int year = 1584;
    int const end_year = 2101;

    while (year <= end_year) {
        if(is_leap_year(year)) {
            printf("%d ", year);
        }
        year += 1;
    }
    putchar('\n');

    return 0;
}
