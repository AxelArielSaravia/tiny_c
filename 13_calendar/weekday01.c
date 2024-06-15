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

typedef enum month month;
enum month {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER,
    MONTH_LEN
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

char const*const WEEKDAY_SNAME[WEEKDAY_LEN] = {
    [SUNDAY]    = "Sun",
    [MONDAY]    = "Mon",
    [TUESDAY]   = "Tue",
    [WEDNESDAY] = "Wed",
    [THURSDAY]  = "Thu",
    [FRIDAY]    = "Fri",
    [SATURDAY]  = "Sat"
};

char const*const MONTH_NAME[MONTH_LEN] = {
    [JANUARY]   = "January",
    [FEBRUARY]  = "February",
    [MARCH]     = "March",
    [APRIL]     = "April",
    [MAY]       = "May",
    [JUNE]      = "June",
    [JULY]      = "July",
    [AUGUST]    = "August",
    [SEPTEMBER] = "September",
    [OCTOBER]   = "October",
    [NOVEMBER]  = "November",
    [DECEMBER]  = "December",
};

int const dayoftheweek_arr[MONTH_LEN] = {
    [JANUARY]   = 0,
    [FEBRUARY]  = 3,
    [MARCH]     = 2,
    [APRIL]     = 5,
    [MAY]       = 0,
    [JUNE]      = 3,
    [JULY]      = 5,
    [AUGUST]    = 1,
    [SEPTEMBER] = 4,
    [OCTOBER]   = 6,
    [NOVEMBER]  = 2,
    [DECEMBER]  = 4,
};

int dayoftheweek(int d, int m, int y) {
    if (m > 1) {
        y -= 1;
    }
    return (y + y/4 - y/100 + dayoftheweek_arr[m] + d) % 7;
}

int main() {
    time_t now = time((void*)0);
    struct tm* date = localtime(&now);
    int wday = dayoftheweek(date->tm_mday, date->tm_mon, date->tm_year);
    printf(
        "%s %d, %d is a %d %s\n",
        MONTH_NAME[date->tm_mon],
        date->tm_mday,
        date->tm_year+1900,
        wday,
        WEEKDAY_NAME[wday]
    );
    return 0;
}
