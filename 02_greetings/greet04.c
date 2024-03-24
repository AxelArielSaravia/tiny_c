#include <stdio.h>
#include <time.h>

char const*const phase[8] = {
    "waxing crescent",
    "at first quarter",
    "waxing gibbous",
    "full",
    "waning gibbous",
    "at last quarter",
    "waning crescent",
    "new"
};

int moon_phase(int year, int month, int day) {
    // in c months goes from 0 to 11
    if (month == 2) {
        day += 31;
    } else if (month > 2) {
        day += 59 + (month - 3) * 30.6 + 0.5;
    }
    int g = (year - 1900) % 19;
    int e = (11 * g + 29) % 30;
    if (e == 25 || e == 24) {
        e += 1;
    }
    return ((((e + day)*6 +  5)% 177)/ 22) & 7;
}

int main(int argc, char* argv[argc]) {
    time_t now;
    struct tm* clock;
    char time_string[64];

    time(&now);
    clock = localtime(&now);
    strftime(
        time_string,
        64,
        "Today is %A, %B %d, %Y%nIt is %r%n",
        clock
    );

    int mp = moon_phase(
        (*clock).tm_year + 1900,
        (*clock).tm_mon,
        (*clock).tm_mday
    );

    printf("Greetings");
    if (argc > 1) {
        printf(", %s", argv[1]);
    }
    printf("!\n%s", time_string);
    printf("The moon is %s\n", phase[mp]);
    return 0;
}
