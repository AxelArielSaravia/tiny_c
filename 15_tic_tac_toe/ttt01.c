#include <stdio.h>

#define BG_BLANK "\x1b[47m"
#define BG_BLACK "\x1b[40m"

#define FG_BLACK "\x1b[30m"
#define FG_RED   "\x1b[31m"
#define FG_BLUE  "\x1b[34m"

#define RESET    "\x1b[0m"

#define X_COLOR FG_RED
#define O_COLOR FG_BLUE

#define GRID_LEN 9
#define CELLS 3

void showgrid(int grid[GRID_LEN]) {
    for (int i = 0; i < GRID_LEN; i += 1) {
        if (i % 2) {
            printf(BG_BLANK);
            printf(FG_BLACK);
        } else {
            printf(BG_BLACK);
        }
        if (grid[i] == -1) {
            printf(O_COLOR);
            printf(" o ");
        } else if (grid[i] == 1) {
            printf(X_COLOR);
            printf(" x ");
        } else {
            printf(" %d ", i + 1);
        }
        printf(RESET);
        if ((i + 1) % 3 == 0) {
            putchar('\n');
        }
    }
    putchar('\n');
}

int main() {
    int grid[GRID_LEN] = {
        0, 0, 0,
        0, 0, 0,
        0, 0, 0
    };
    puts("Tic-Tac-Toe");
    showgrid(grid);
}
