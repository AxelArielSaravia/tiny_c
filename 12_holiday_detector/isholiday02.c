#include <stdio.h>
#include <time.h>

typedef struct holiday holiday;
struct holiday {
    int month;
    int day;
    char const* name;
};

typedef enum holidays holidays;
enum holidays {
    HDAY_NEW_YEAR,
    HDAY_25_MAY,
    HDAY_INDEPENDENCE,
    HDAY_CHRISTMAS,
    HDAY_LEN
};

typedef struct holidays_info holidays_info;
struct holidays_info {
    int months[HDAY_LEN];
    int days[HDAY_LEN];
    char const* names[HDAY_LEN];
};

holidays_info const HOLIDAYS = (holidays_info){
    .months = {
        [HDAY_NEW_YEAR] = 0,
        [HDAY_25_MAY] = 4,
        [HDAY_INDEPENDENCE] = 6,
        [HDAY_CHRISTMAS] = 11,
    },
    .days = {
        [HDAY_NEW_YEAR] = 1,
        [HDAY_25_MAY] = 25,
        [HDAY_INDEPENDENCE] = 7,
        [HDAY_CHRISTMAS] = 25,
    },
    .names = {
        [HDAY_NEW_YEAR] = "New Years Day",
        [HDAY_25_MAY] = "25 de Mayo",
        [HDAY_INDEPENDENCE] = "Independence Day",
        [HDAY_CHRISTMAS] = "Chirstmas",
    },
};

typedef enum days days;
enum days {
    DAY_SUNDAY,
    DAY_MONDAY,
    DAY_TUESDAY,
    DAY_WEDNESDAY,
    DAY_THURSDAY,
    DAY_FRIDAY,
    DAY_SATURDAY,
    DAY_LEN
};

char const*const DAYS[DAY_LEN] = {
    [DAY_SUNDAY] = "Sunday",
    [DAY_MONDAY] = "Monday",
    [DAY_TUESDAY] = "Tuesday",
    [DAY_WEDNESDAY] = "Wednesday",
    [DAY_THURSDAY] = "Thurday",
    [DAY_FRIDAY] = "Friday",
    [DAY_SATURDAY] = "Saturday"
};

_Bool isholiday(holiday* h) {
    for (int i = 0; i < HDAY_LEN; i += 1) {
        if (
            h->month == HOLIDAYS.months[i]
            && h->day == HOLIDAYS.days[i]
        ) {
            h->name = HOLIDAYS.names[i];
            return (_Bool)1;
        }
    }
    return (_Bool)0;
}

int main() {
    time_t now = time((void*)0);
    struct tm* today = localtime(&now);

    holiday h = (holiday){
        .day = today->tm_mday,
        .month = today->tm_mon,
    };

    _Bool ok = isholiday(&h);

    printf(
        "Today is %02d/%02d/%04d, ",
        today->tm_mday,
        today->tm_mon,
        today->tm_year+1900
    );

    if (ok) {
        printf("is %s\n", h.name);
    } else {
        puts("not a holiday");
    }

    return 0;
}
