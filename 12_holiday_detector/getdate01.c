#include <stdio.h>
#include <time.h>

int main() {
    time_t now = time((void*)0);
    struct tm* today = localtime(&now);

    int month = today->tm_mon + 1;
    int day = today->tm_mday;
    int weekday = today->tm_wday;
    int year = today->tm_year + 1900;

    printf("Today is %d, %d-%d-%d\n", weekday, day, month, year);

    return 0;
}
