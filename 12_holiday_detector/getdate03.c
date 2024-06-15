#include <stdio.h>
#include <time.h>

char const*const days[] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
};

int main() {
    struct tm day = (struct tm){
        .tm_mon = 4 - 1,
        .tm_mday = 12,
        .tm_year = 2022 - 1900,
    };

    mktime(&day);

    printf(
        "%02d/%02d/%04d is on a %s\n",
        day.tm_mday,
        day.tm_mon + 1,
        day.tm_year+1900,
        days[day.tm_wday]
    );

    return 0;
}
