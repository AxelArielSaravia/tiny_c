#include <stdio.h>
#include <time.h>

typedef enum weekday weekday;
enum weekday {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    WEEKDAY_LEN
};

char const*const WEEKDAY_NAME[WEEKDAY_LEN] = {
    [SUNDAY]    = "Sunday",
    [MONDAY]    = "Monday",
    [TUESDAY]   = "Tuesday",
    [WEDNESDAY] = "Wednesday",
    [THURSDAY]  = "Thurday",
    [FRIDAY]    = "Friday",
    [SATURDAY]  = "Saturday"
};

int main() {
    time_t now;
    time(&now);

    struct tm* date = localtime(&now);

    int first = date->tm_wday - (date->tm_mday % 7) + 1;
    if (first < 0) {
        first += 7;
    }

    printf("The first of this month was on a %s\n", WEEKDAY_NAME[first]);

    return 0;
}
