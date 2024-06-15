#include <stdio.h>
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

#define WEEK_HEADER "Sun Mon Tue Wed Thu Fri Sat\n"

_Bool is_leap_year(int year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

void print_week(
    int years[2],
    int months[2],
    int days[7],
    int week_no,
    int curr_day
) {
    if (years[1] != -1) {
        printf("%-9d - %-9d\n", years[0], years[1]);

    } else {
        printf("%-9d\n", years[0]);
    }
    if (months[1] != -1) {
        printf("%-9s - %-9s\n", MONTH_NAME[months[0]], MONTH_NAME[months[1]]);
    } else {
        printf("%-9s\n", MONTH_NAME[months[0]]);
    }
    printf("No.|");
    printf(WEEK_HEADER);

    printf("%2d |", week_no);
    for (int i = 0; i < 7; i += 1) {
        if (curr_day == days[i]) {
            printf("[%2d]", days[i]);
        } else {
            printf(" %2d ", days[i]);
        }
    }
    putchar('\n');
}

int main() {
    time_t now = time((void*)0);
    struct tm* date = localtime(&now);

    int year = date->tm_year + 1900;
    int month = date->tm_mon;
    int curr_day = date->tm_mday;

    int days[7] = {0};
    int months[2] = {-1, -1};
    int years[2] = {-1, -1};

    //sunday
    int day = date->tm_mday - date->tm_wday;

    int week_no = (9 + date->tm_yday - date->tm_wday) / 7;
    if (week_no == 0) {
        week_no = 52;
    }

    if (is_leap_year(year)) {
        month_days[FEBRUARY] = 29;
    }

    if (day < 1) {
        if (month - 1 < JANUARY) {
            year -= 1;
            month = DECEMBER;
        } else {
            month -= 1;
        }
        day = month_days[month] + day;
    }

    days[0] = day;
    day += 1;

    int month_end = month_days[month];
    int i = 1;

    while (i < 7 && day <= month_end) {
        days[i] = day;
        day += 1;
        i += 1;
    }

    years[0] = year;
    months[0] = month;

    if (i < 7 && day > month_end) {
        if (month + 1 == MONTH_LEN) {
            years[1] = year + 1;
            months[1] = JANUARY;
            year += 1;
            month = JANUARY;
        } else {
            month += 1;
            months[1] = month;
        }
        day = 1;
        while (i < 7) {
            days[i] = day;
            day += 1;
            i += 1;
        }
    }

    print_week(years, months, days, week_no, curr_day);
    return 0;
}
