#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

#ifndef _ISHOLIDAY_C
#define _ISHOLIDAY_C

int weeknumber(unsigned int day, int wday);
_Bool isholiday(int mday, int wday, int mon);

#endif

#ifndef _YEAR_C
#define _YEAR_C

void print_center(int text_len, char const* text, int width);
_Bool is_leap_year(int year);

#endif
