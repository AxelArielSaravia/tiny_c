#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    putenv("TZ=UTC");
    tzset();
    time_t epoch = 0;
    printf("Time is %s", ctime(&epoch));
    return 0;
}
