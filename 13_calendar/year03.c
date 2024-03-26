#include <assert.h>
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

#define COLUMNS 3

#define WEEK_HEADER_LEN 29
#define WEEK_HEADER " Sun Mon Tue Wed Thu Fri Sat "
#define C_SPLITER_LEN 2
#define C_SPLITER "  "
#define DAY_F " %2d "
#define DAY_SPACE "    "
#define DAY_SPLITER "   "


void print_center(int text_len, char const* text, int width) {
    assert(text_len <= width);

    int indent = (width - text_len) / 2;

    int s = 0;
    while (s < indent) {
        putchar(' ');
        s += 1;
    }
    printf("%s", text);
    s += text_len;
    while (s < width) {
        putchar(' ');
        s += 1;
    }
}

_Bool is_leap_year(int year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

int main(int argc, char const* argv[argc]) {
    time_t now = time((void*)0);
    struct tm* date = localtime(&now);

    int curr_day = date->tm_mday;
    int curr_month = date->tm_mon;
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
        *date = (struct tm){
            .tm_year = date->tm_year,
            .tm_mday = 1,
        };
        mktime(date);
    }

    int dotm[MONTH_LEN];
    int months[COLUMNS];
    int days[COLUMNS];
    int dows[COLUMNS];

    int year = date->tm_year + 1900;
    dotm[JANUARY] = date->tm_wday;

    if (is_leap_year(year)) {
        month_days[FEBRUARY] = 29;
    }

    for (int month = FEBRUARY; month < MONTH_LEN; month += 1) {
        dotm[month] = (month_days[month-1] + dotm[month-1]) % 7;
    }


    int cal_size;
    if (COLUMNS - 1 >= 0) {
        cal_size = COLUMNS * WEEK_HEADER_LEN + (COLUMNS - 1) * C_SPLITER_LEN;
    } else {
        fprintf(stderr, "WARN: Checks the COLUMNS parameter, maybe is 0 or less.\n");
        return EXIT_FAILURE;
    }

    {
        char year_s[12] = {0};
        int n = sprintf(year_s, "%04d", year);
        if (n == -1) {
            fprintf(stderr, "ERROR: Fails seting a buffer\n");
            return EXIT_FAILURE;
        }
        print_center(4, year_s, cal_size);
        putchar('\n');
    }

    for (int month = JANUARY; month < MONTH_LEN; month += COLUMNS) {
        for (int c = 0; c < COLUMNS; c += 1) {
            int m = month + c;
            months[c] = m;
            days[c] = 1;
            dows[c] = 0;

            print_center(MONTH_NAME_LEN[m], MONTH_NAME[m], WEEK_HEADER_LEN);
            if (c < COLUMNS -1) {
                printf(C_SPLITER);
            }
        }
        putchar('\n');

        for (int c = 0; c < COLUMNS; c += 1) {
            printf(WEEK_HEADER);
            if (c < COLUMNS -1) {
                printf(C_SPLITER);
            }
        }
        putchar('\n');

        int mends = 0;
        while (mends < COLUMNS) {
            for (int c = 0; c < COLUMNS; c += 1) {
                int mon = months[c];
                while (dows[c] < 7) {
                    if (
                        (days[c] == 1 && dows[c] < dotm[c])
                        || days[c] > month_days[mon]
                    ) {
                        printf(DAY_SPACE);
                    } else if (days[c] <= month_days[mon]) {
                        if (months[c] == curr_month && days[c] == curr_day) {
                            printf("[%2d]", days[c]);
                        } else {
                            printf(DAY_F, days[c]);
                        }
                        days[c] += 1;
                    }
                    dows[c] += 1;
                }
                dows[c] = 0;
                if (days[c] > month_days[mon]) {
                    mends += 1;
                }
                if (c < COLUMNS - 1) {
                    printf("   ");
                }
            }
            putchar('\n');
        }
        putchar('\n');
    }

    return EXIT_SUCCESS;
}
