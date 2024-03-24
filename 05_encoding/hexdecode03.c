#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_LINE 18
#define LENGTH (BYTES_PER_LINE*3+4)

void hexdencode_v1(size_t len, char line[len]);
void hexdencode_v2(size_t len, char line[len]);

int main() {
    char line[LENGTH];
    char* r = fgets(line, LENGTH, stdin);
    if (r == (void*)0 || strncmp(line, "HEX ENCODE", 10) != 0) {
        fprintf(stderr, "Invalid HEX ENCODE data\n");
        exit(1);
    }
    if (strncmp(line+11, "v2.0", 4) == 0) {
        hexdencode_v2(LENGTH, line);
    } else {
        hexdencode_v1(LENGTH, line);
    }
    return 0;
}

void hexdencode_v1(size_t len, char line[len]) {
    char* r;
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
}

void hexdencode_v2(size_t len, char line[len]) {
    char* r = fgets(line, LENGTH, stdin);
    int line_n = 2;
    while (r) {
        if (strncmp(line, "HEX ENCODE END", 14) == 0) {
            return;
        }
        int hex = 0;
        int sum = 0;
        char* w = strtok(line, " ");
        while (w) {
            sscanf(w, "%02x", &hex);
            w = strtok((void*)0, " ");
            if (w) {
                printf("%c", hex);
                sum += hex;
            } else {
                break;
            }
        }
        if (sum % 0x100 != hex) {
            fprintf(stderr,"\nChecksum error at Line %d\n", line_n);
            fprintf(stderr,"Unable to decode data\n");
            exit(1);
            return;
        }
        r = fgets(line, LENGTH, stdin);
        line_n += 1;
    }
    fprintf(stderr,"\nChecksum error at Line %d\n", line_n);
    fprintf(stderr, "Unable to read a line. Maybe, the hex code terminate command is not provided\n");
    exit(1);
}
