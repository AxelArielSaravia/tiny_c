#include <stdio.h>

#define BYTES_PER_LINE 18
#define LENGTH (BYTES_PER_LINE*3+1)

int main() {
    char line[LENGTH];
    int x = 0;
    for (int ch = getchar(); ch != EOF; ch = getchar()) {
        if (ch == '\n' || x == LENGTH - 1) {
            line[x] = '\0';
            printf("%s\n", line);
            x = 0;
        } else {
            line[x] = ch;
            x += 1;
        }
    }
    return 0;
}
