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
    if (month == 2) {
        day += 31;
    } else if (month > 2) {
        day += 59 + (month - 3) * 30.6 + 0.5;
    }
    int g = (year - 1900) % 19;
    int e = (11*g + 29) % 30;
    if (e == 25 || e == 24) {
        e += 1;
    }
    return ((((e + day)*6 +  5)% 177)/ 22) & 7;
}
