#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLT_STR_LEN 64
#define spacefy_SYMBOL '_'

/*return the length of the string*/
_Bool spacefy(float num, char str[FLT_STR_LEN]) {
    if (num < 1) {
        return (_Bool)0;
    }

    snprintf(str, FLT_STR_LEN, "%.0f", num);
    if (num < 1000) {
        return (_Bool)1;
    }
    int len = strlen(str);
    int mv_len = 3;

    for (int k = len - 3; 0 <= k; k -= 3) {
        memmove(&str[k+1], &str[k], mv_len);
        str[k] = spacefy_SYMBOL;
        mv_len += 4;
    }

    return (_Bool)1;
}

int main() {
    int items;
    int draws;

    char num[FLT_STR_LEN] = {0};
    printf("Number of items: ");
    scanf("%d", &items);
    printf("Items to draw: ");
    scanf("%d", &draws);

    unsigned long i = items;
    unsigned long d = draws;

    if (i == 0 || d == 0 || d > i) {
        fprintf(stderr, "Error: Bad inputs\n");
        return EXIT_FAILURE;
    }

    for (int k = 1; k < draws; k += 1) {
        i *= (items - k);
        d *= (draws - k);
    }
    float res = (float)i / (float)d;
    spacefy(res, num);

    printf("Your odds of drawing %d ", draws);
    printf("items from %d are:\n", items);

    printf("\t1:%s\n", num);

    return 0;
}
