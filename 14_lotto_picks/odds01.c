#include <stdio.h>


int main(int argc, char const* argv[argc]) {
    int ow;
    int ol;
    printf("Chances of happening: ");
    scanf("%d", &ow);
    printf("Chances of not happening: ");
    scanf("%d", &ol);

    printf(
        "Your odds of winning are[CA] %2.1f%%, or %d:%d\n",
        (float)ow/(float)(ow+ol) * 100,
        ow,
        ol
    );

    return 0;
}
