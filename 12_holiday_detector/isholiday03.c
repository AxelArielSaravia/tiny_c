#include <stdio.h>
#include <stdlib.h>
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
    DAYS_LEN
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

char const*const WEEKDAYS[DAYS_LEN] = {
    [SUNDAY] = "Sunday",
    [MONDAY] = "Monday",
    [TUESDAY] = "Tuesday",
    [WEDNESDAY] = "Wednesday",
    [THURSDAY] = "Thurday",
    [FRIDAY] = "Friday",
    [SATURDAY] = "Saturday"
};

typedef struct holiday holiday;
struct holiday {
    int month;
    int day;
    int wday;
    char const* name;
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

int main(int argc, char const* argv[argc]) {
    time_t now;
    struct tm* date;
    if (argc < 4) {
        now = time((void*)0);
        date = localtime(&now);
    } else {
        int year = atoi(argv[1]);
        int mon = atoi(argv[2]);
        int day = atoi(argv[3]);
        date = &(struct tm){
            .tm_mon = mon - 1,
            .tm_mday = day,
            .tm_year = year - 1900,
        };
        mktime(date);
    }

    holiday h = (holiday){
        .day = date->tm_mday,
        .wday = date->tm_wday,
        .month = date->tm_mon,
    };

    _Bool ok = isholiday(&h);

    printf(
        "Today is %02d/%02d/%04d, ",
        date->tm_mday,
        date->tm_mon+1,
        date->tm_year+1900
    );

    if (ok) {
        printf("is %s\n", h.name);
    } else {
        puts("not a holiday");
    }

    return 0;
}
