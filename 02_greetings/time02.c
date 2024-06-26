#include <stdio.h>
#include <time.h>

int main() {
    time_t now;
    time(&now);

    struct tm* clock = localtime(&now);
//  struct tm
//  int tm_sec;     /* Seconds. [0-60] (1 leap second) */
//  int tm_min;     /* Minutes. [0-59] */
//  int tm_hour;    /* Hours.   [0-23] */
//  int tm_mday;    /* Day.     [1-31] */
//  int tm_mon;     /* Month.   [0-11] */
//  int tm_year;    /* Year     - 1900.*/
//  int tm_wday;    /* Day of week. [0-6] */
//  int tm_yday;    /* Days in year.[0-365] */
//  int tm_isdst;   /* DST. [-1/0/1]*/

    puts("time details:");
    printf(" Day of the year: %d\n", (*clock).tm_yday);
    printf(" Day of the week: %d\n", (*clock).tm_wday);
    printf("            Year: %d\n", (*clock).tm_year + 1900);
    printf("           Month: %d\n", (*clock).tm_mon + 1);
    printf("Day of the month: %d\n", (*clock).tm_mday);
    printf("            Hour: %d\n", (*clock).tm_hour);
    printf("          Minute: %d\n", (*clock).tm_min);
    printf("          Second: %d\n", (*clock).tm_sec);

    return 0;
}
