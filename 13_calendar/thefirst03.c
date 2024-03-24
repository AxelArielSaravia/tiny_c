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
    [SATURDAY]  = "Saturday",
};

int first_wday_month(int wday, int mday) {
    int res = wday - (mday % 7) + 1;
    if (res < 0) {
        res += 7;
    }
    return res;
}

int main() {
    time_t now = time((void*)0);
    struct tm* date = localtime(&now);
    int first = first_wday_month(date->tm_wday, date->tm_mday);
    printf("The first wday of this month was on a %s\n", WEEKDAY_NAME[first]);

    return 0;
}
