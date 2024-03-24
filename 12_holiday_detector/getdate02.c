#include <stdio.h>
#include <time.h>

char* weekdays[7] = {
    "sunday",
    "monday",
    "tuesday",
    "wednesday",
    "thursday",
    "friday",
    "saturday"
};

char* months[12] = {
    "january",
    "february",
    "march",
    "april",
    "may",
    "june",
    "july",
    "august",
    "september",
    "october",
    "november",
    "december"
};

int main() {
    time_t now = time((void*)0);
    struct tm* today = localtime(&now);

    int month = today->tm_mon;
    int day = today->tm_mday;
    int weekday = today->tm_wday;
    int year = today->tm_year + 1900;

    printf("Today is %s, %s %d, %d\n", weekdays[weekday], months[month], day, year);

    return 0;
}
