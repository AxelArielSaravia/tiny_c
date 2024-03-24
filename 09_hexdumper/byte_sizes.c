#include <stdio.h>
#include <math.h>

int main() {
    unsigned long byte = sizeof(char) * 8;
    unsigned long word = sizeof(short) * 8;
    unsigned long double_word = sizeof(int) * 8;
    unsigned long quad_word = sizeof(long) * 8;

    char const* print_str = "%11s %2lu bits %21.f\n";

    printf(print_str, "Byte", byte, pow(2, byte));
    printf(print_str, "Word", word, pow(2, word));
    printf(print_str, "DoubleWord", double_word, pow(2, double_word));
    printf(print_str, "QuadWord", quad_word, pow(2, quad_word));

    return 0;
}
