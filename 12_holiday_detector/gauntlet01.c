#include <stdio.h>

typedef enum weekday weekday;
enum weekday {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    WDAYS_LEN
};

typedef enum months months;
enum months {
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
    MONTHS_LEN
};

char const*const WEEKDAYS[WDAYS_LEN] = {
    [SUNDAY] = "Sunday",
    [MONDAY] = "Monday",
    [TUESDAY] = "Tuesday",
    [WEDNESDAY] = "Wednesday",
    [THURSDAY] = "Thurday",
    [FRIDAY] = "Friday",
    [SATURDAY] = "Saturday"
};

char const*const MONTHS[MONTHS_LEN] = {
    [JANUARY] = "January",
    [FEBRUARY] = "February",
    [MARCH] = "March",
    [APRIL] = "April",
    [MAY] = "May",
    [JUNE] = "June",
    [JULY] = "July",
    [AUGUST] = "August",
    [SEPTEMBER] = "September",
    [OCTOBER] = "October",
    [NOVEMBER] = "November",
    [DECEMBER] = "December",
};

int const MONTH_DAYS[MONTHS_LEN] = {
    [JANUARY] = 31,
    [FEBRUARY] = 29,
    [MARCH] = 31,
    [APRIL] = 30,
    [MAY] = 31,
    [JUNE] = 30,
    [JULY] = 31,
    [AUGUST] = 31,
    [SEPTEMBER] = 30,
    [OCTOBER] = 31,
    [NOVEMBER] = 30,
    [DECEMBER] = 31,
};

int main() {
    int start_day = MONDAY;
    int year_day = 1;
    int year = 2024;
    for (int m = 0; m < MONTHS_LEN; m += 1) {
        for (int month_day = 1; month_day <= MONTH_DAYS[m]; month_day += 1) {
            printf(
                "%s, %s %d, %d\n",
                WEEKDAYS[(year_day + start_day - 1) % 7],
                MONTHS[m],
                month_day,
                year
            );
            year_day += 1;
        }
    }
    return 0;
}
