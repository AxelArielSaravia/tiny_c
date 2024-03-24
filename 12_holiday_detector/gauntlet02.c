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

typedef enum holidays holidays;
enum holidays {
    HDAY_NEW_YEAR,
    HDAY_25_MAY,
    HDAY_INDEPENDENCE,
    HDAY_MOTHERS,
    HDAY_CHRISTMAS,
    HDAYS_LEN
};

typedef struct holidays_info holidays_info;
struct holidays_info {
    int months[HDAYS_LEN];
    int days[HDAYS_LEN]; //can be a month_day or a week_day
    int wnum[HDAYS_LEN]; //if days is a week_day wnum is set
    char const* names[HDAYS_LEN];
};

holidays_info const HOLIDAYS = (holidays_info){
    .months = {
        [HDAY_NEW_YEAR] = JANUARY,
        [HDAY_25_MAY] = MAY,
        [HDAY_INDEPENDENCE] = JULY,
        [HDAY_MOTHERS] = OCTOBER,
        [HDAY_CHRISTMAS] = DECEMBER,
    },
    .days = {
        [HDAY_NEW_YEAR] = 1,
        [HDAY_25_MAY] = 25,
        [HDAY_INDEPENDENCE] = 7,
        [HDAY_MOTHERS] = SUNDAY,
        [HDAY_CHRISTMAS] = 25,
    },
    .wnum = {
        [HDAY_NEW_YEAR] = 0,
        [HDAY_25_MAY] = 0,
        [HDAY_INDEPENDENCE] = 0,
        [HDAY_MOTHERS] = 3,
        [HDAY_CHRISTMAS] = 0,
    },
    .names = {
        [HDAY_NEW_YEAR] = "New Years Day",
        [HDAY_25_MAY] = "25 de Mayo",
        [HDAY_INDEPENDENCE] = "Independence Day",
        [HDAY_MOTHERS] = "Mothers Day",
        [HDAY_CHRISTMAS] = "Chirstmas",
    },
};

typedef struct holiday holiday;
struct holiday {
    int month;
    int day;
    int wday;
    char const* name;
};

weekday const FIRST_WEEKDAY = MONDAY;

int weeknumber(unsigned int day, int wday) {
    int weeknum = 1;

    //Monday as first day of the week
    wday -= FIRST_WEEKDAY;
    if (wday < 0) {
        wday += 7;
    }

    int offset = 0;

    int curr_wday = (day - 1) % 7;
    if (wday < curr_wday) {
        offset = wday + 7 - curr_wday;
    } else if (wday > curr_wday) {
        offset = (wday + 7 - curr_wday) % 7;
    }

    if (7-offset < day && day < 15-offset) {
        weeknum = 2;
    } else if (14-offset < day && day < 22-offset) {
        weeknum = 3;
    } else if (21-offset < day && day < 29-offset) {
        weeknum = 4;
    } else if (28-offset < day && day < 36-offset) {
        weeknum = 5;
    } else {
        weeknum = 6;
    }
    return weeknum;
}

_Bool isholiday(holiday* h) {
    for (int i = 0; i < HDAYS_LEN; i += 1) {
        if (
            h->month == HOLIDAYS.months[i]
            && (
                (!HOLIDAYS.wnum[i] && h->day == HOLIDAYS.days[i])
                || (
                    h->wday == HOLIDAYS.days[i]
                    && weeknumber(h->day, h->wday) == HOLIDAYS.wnum[i]
                )
            )
        ) {
            h->name = HOLIDAYS.names[i];
            return (_Bool)1;
        }
    }
    return (_Bool)0;
}

int main() {
    int start_day = MONDAY;
    int year_day = 1;
    int year = 2024;
    for (int m = 0; m < MONTHS_LEN; m += 1) {
        for (int month_day = 1; month_day <= MONTH_DAYS[m]; month_day += 1) {
            holiday h = (holiday){
                .day = month_day,
                .wday = (year_day + start_day - 1) % 7,
                .month = m,
            };

            if (isholiday(&h)) {
                printf(
                    "%s -- %s, %s %d, %d\n",
                    h.name,
                    WEEKDAYS[h.wday],
                    MONTHS[m],
                    month_day,
                    year
                );
            }
            year_day += 1;
        }
    }
    return 0;
}
