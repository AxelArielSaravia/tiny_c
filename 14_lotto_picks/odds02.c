#include <stdio.h>

int main() {
    int items;
    int draws;

    printf("Number of items: ");
    scanf("%d", &items);
    printf("Items to draw: ");
    scanf("%d", &draws);

    unsigned long i = items;
    unsigned long d = draws;

    for (int k = 1; k < draws; k += 1) {
        i *= (items - k);
        d *= (draws - k);
    }
    float res = (float)i / (float)d;

    printf("Your odds of drawing %d ", draws);
    printf("items from %d are:\n", items);

    printf("\t1:%.0f\n", res);

    return 0;
}
