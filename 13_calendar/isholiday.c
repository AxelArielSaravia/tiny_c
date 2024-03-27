#include "holiday_year.h"

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
    enum months months[HDAYS_LEN];
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

int weeknumber(unsigned int day, int wday) {
    int weeknum = 1;
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

_Bool isholiday(int mday, int wday, int mon) {
    for (int i = 0; i < HDAYS_LEN; i += 1) {
        if (
            mon == HOLIDAYS.months[i]
            && (
                (!HOLIDAYS.wnum[i] && mday == HOLIDAYS.days[i])
                || (
                    wday == HOLIDAYS.days[i]
                    && weeknumber(mday, wday) == HOLIDAYS.wnum[i]
                )
            )
        ) {
            return (_Bool)1;
        }
    }
    return (_Bool)0;
}
