#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_LINE 18
#define LENGTH (BYTES_PER_LINE*3+1)

int main() {
    char line[LENGTH];
    char* r = fgets(line, LENGTH, stdin);
    if (r == (void*)0 || strncmp(line, "HEX ENCODE", 10) != 0) {
        fprintf(stderr, "Invalid HEX ENCODE data\n");
        exit(1);
    }
    int x = 0;
    int hex;
    for (int ch = getchar(); ch != EOF; ch = getchar()) {
        if (ch == '\n' || x == LENGTH - 1) {
            line[x] = '\0';
            if (strncmp(line, "HEX ENCODE END", 14) == 0) {
                break;
            }
            r = strtok(line, " ");
            while (r) {
                sscanf(r, "%02x", &hex);
                printf("%c", hex);
                r = strtok((void*)0, " ");
            }
            x = 0;
        } else {
            line[x] = ch;
            x += 1;
        }
    }
    return 0;
}
