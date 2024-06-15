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

#define COLUMNS 4

#define COLOR_RESET "\x1b[0m"
#define FG_RED "\x1b[31m"
#define FG_YELLOW "\x1b[33m"

#define BG_WHITE "\x1b[47m"
#define FG_BLACK "\x1b[30m"

#define FG_COLOR FG_YELLOW

#define C_SPLITER_LEN 1
#define C_SPLITER " "
#define DAY_F1 "%s%2d%s"
#define DAY_F2 "%2d"
#define DAY_SPACE "  "
#define CURR_DAY_F "%s%s%2d%s"

#define WEEK_HEADER_LEN 14
#define WEEK_HEADER_F "%sSu%sMo%sTu%sWe%sTh%sFr%sSa%s"

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
            .tm_mon = 0,
        };
        mktime(date);
    }

    int fst_wday[MONTH_LEN];
    int months[COLUMNS];
    int days[COLUMNS];
    int week_days[COLUMNS];
    _Bool colors[COLUMNS];

    int year = date->tm_year + 1900;
    fst_wday[JANUARY] = date->tm_wday;

    if (is_leap_year(year)) {
        month_days[FEBRUARY] = 29;
    }

    for (int mon = FEBRUARY; mon < MONTH_LEN; mon += 1) {
        fst_wday[mon] = (month_days[mon-1] + fst_wday[mon-1]) % 7;
    }


    int calc_size;
    if (COLUMNS - 1 >= 0) {
        calc_size = COLUMNS * WEEK_HEADER_LEN + (COLUMNS - 1) * C_SPLITER_LEN;
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
        print_center(4, year_s, calc_size);
        putchar('\n');
    }

    for (int mon = JANUARY; mon < MONTH_LEN; mon += COLUMNS) {
        for (int c = 0; c < COLUMNS; c += 1) {
            int s_mon = mon + c;
            months[c] = s_mon;
            days[c] = 1;
            colors[c] = 0;

            print_center(MONTH_NAME_LEN[s_mon], MONTH_NAME[s_mon], WEEK_HEADER_LEN);
            if (c < COLUMNS -1) {
                printf(C_SPLITER);
            }
        }
        putchar('\n');

        for (int c = 0; c < COLUMNS; c += 1) {
            printf(
                WEEK_HEADER_F,
                FG_COLOR,
                COLOR_RESET,
                FG_COLOR,
                COLOR_RESET,
                FG_COLOR,
                COLOR_RESET,
                FG_COLOR,
                COLOR_RESET
            );
            if (c < COLUMNS -1) {
                printf(C_SPLITER);
            }
        }
        putchar('\n');

        int m_ends = 0;
        while (m_ends < COLUMNS) {
            for (int c = 0; c < COLUMNS; c += 1) {
                int m = months[c];
                week_days[c] = 0;
                while (week_days[c] < 7) {
                    if (
                        (days[c] == 1 && week_days[c] < fst_wday[m])
                        || days[c] > month_days[m]
                    ) {
                        printf(DAY_SPACE);
                    } else if (days[c] <= month_days[m]) {
                        if (months[c] == curr_month && days[c] == curr_day) {
                            printf(CURR_DAY_F, BG_WHITE, FG_BLACK, days[c], COLOR_RESET);
                        } else {
                            if (colors[c]) {
                                printf(DAY_F1, FG_COLOR, days[c], COLOR_RESET);
                            } else {
                                printf(DAY_F2,days[c]);
                            }
                        }
                        days[c] += 1;
                    }
                    colors[c] = !colors[c];
                    week_days[c] += 1;
                }

                if (days[c] > month_days[m]) {
                    m_ends += 1;
                }
                if (c < COLUMNS - 1) {
                    printf(C_SPLITER);
                }
            }
            putchar('\n');
        }
        putchar('\n');
    }

    return EXIT_SUCCESS;
}
