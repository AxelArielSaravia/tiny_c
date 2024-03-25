#include <assert.h>
#include <stdio.h>
#include <time.h>

#define COLUMNS 3;

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

int main() {
    
    return 0;
}
