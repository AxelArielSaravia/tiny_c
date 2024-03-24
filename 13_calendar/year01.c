#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
int const MONTH_NAME_LEN[MONTH_LEN] = {
    [JANUARY]   = 7,
    [FEBRUARY]  = 8,
    [MARCH]     = 5,
    [APRIL]     = 5,
    [MAY]       = 3,
    [JUNE]      = 4,
    [JULY]      = 4,
    [AUGUST]    = 6,
    [SEPTEMBER] = 9,
    [OCTOBER]   = 7,
    [NOVEMBER]  = 8,
    [DECEMBER]  = 8,
};

int month_days[MONTH_LEN] = {
    [JANUARY]   = 31,
    [FEBRUARY]  = 28,
    [MARCH]     = 31,
    [APRIL]     = 30,
    [MAY]       = 31,
    [JUNE]      = 30,
    [JULY]      = 31,
    [AUGUST]    = 31,
    [SEPTEMBER] = 30,
    [OCTOBER]   = 31,
    [NOVEMBER]  = 30,
    [DECEMBER]  = 31
};

_Bool is_leap_year(int year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

int main(int argc, char const* argv[argc]) {
    time_t now = time((void*)0);
    struct tm* date = localtime(&now);

    int curr_day;
    int curr_month;

    _Bool no_arg = (_Bool)1;

    if (argc > 1) {
        int year_arg = atol(argv[1]);
        if (0 < year_arg) {
            no_arg = (_Bool)0;
            curr_day = -1;
            curr_month = -1;

            *date = (struct tm){
                .tm_year = year_arg - 1900,
                .tm_mday = 1,
            };
            mktime(date);
        }
    }
    if (no_arg) {
        curr_day = date->tm_mday;
        curr_month = date->tm_mon;

        *date = (struct tm){
            .tm_year = date->tm_year,
            .tm_mday = 1,
        };
        mktime(date);
    }

    int year = date->tm_year + 1900;
    int month = date->tm_mon;

    if (is_leap_year(year)) {
        month_days[FEBRUARY] = 29;
    }
    printf("month_n: %d\n", month);
    
}
