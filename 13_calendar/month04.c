#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

#define WEEK_HEADER_LEN 29
#define WEEK_HEADER " Sun Mon Tue Wed Thu Fri Sat \n"
#define LINEF       " %d2  %d2  %d2"

_Bool is_leap_year(int year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

int first_wday_month(int wday, int mday) {
    int res = wday - (mday % 7) + 1;
    if (res < 0) {
        res += 7;
    }
    return res;
}

void print_center(int month, int year) {
    char spaces[WEEK_HEADER_LEN] = {0};
    int k = (WEEK_HEADER_LEN - (MONTH_NAME_LEN[month] + 5)) / 2;
    for (int i = 0; i < k; i += 1) {
        spaces[i] = ' ';
    }

    printf("%s%s %04d\n", spaces, MONTH_NAME[month], year);
}

int main(int argc, char const* argv[argc]) {
    time_t now = time((void*)0);
    struct tm* date = localtime(&now);

    if (argc > 2) {
        int month_arg = atol(argv[1]);
        int year_arg = atol(argv[2]);
        if (0 < month_arg && month_arg < 13 && 0 < year_arg) {
            *date = (struct tm){
                .tm_year = year_arg - 1900,
                .tm_mon = month_arg - 1,
                .tm_mday = 1,
            };
            mktime(date);
        }
    }

    int year = date->tm_year + 1900;
    int month = date->tm_mon;
    int curr_day = date->tm_mday;

    int fst_wday_month = first_wday_month(date->tm_wday, date->tm_mday);

    int day = -fst_wday_month + 1;

    if (is_leap_year(year)) {
        month_days[FEBRUARY] = 29;
    }

    int month_end = month_days[month];

    // printf("%s %d\n", MONTH_NAME[month], year);
    print_center(month, year);
    printf(WEEK_HEADER);
    while (day <= month_end) {
        for (int i = 0; i < 7; i += 1) {
            if (month_end < day) {
                break;
            } else if (day < 1) {
                printf("    ");
            } else if (day == curr_day) {
                printf("[%2d]", day);
            } else {
                printf(" %2d ", day);
            }
            day += 1;
        }
        putchar('\n');
    }

    return 0;
}
