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

#define X_VAL 1
#define O_VAL -1

void showgrid(int grid[GRID_LEN]) {
    for (int i = 0; i < GRID_LEN; i += 1) {
        if (i % 2) {
            printf(BG_BLANK);
            printf(FG_BLACK);
        } else {
            printf(BG_BLACK);
        }
        if (grid[i] == O_VAL) {
            printf(O_COLOR);
            printf(" o ");
        } else if (grid[i] == X_VAL) {
            printf(X_COLOR);
            printf(" x ");
        } else {
            printf(" %d ", i+1);
        }
        printf(RESET);
        if ((i + 1) % 3 == 0) {
            putchar('\n');
        }
    }
    putchar('\n');
}

int prompt(int p, char const turn) {
    printf("%c's turn: Pick a square, 0 to quit: ", turn);

    int square = -1;
    scanf("%d", &square);

    if (square < 0 || square > 9) {
        return -1;
    }

    return square;
}

#define WINNIN_POS 8
int winner(int grid[GRID_LEN]) {
    int slice[WINNIN_POS];
    slice[0] = grid[0] + grid[1] + grid[2];
    slice[1] = grid[3] + grid[4] + grid[5];
    slice[2] = grid[6] + grid[7] + grid[8];
    slice[3] = grid[0] + grid[3] + grid[6];
    slice[4] = grid[1] + grid[4] + grid[7];
    slice[5] = grid[2] + grid[5] + grid[8];
    slice[6] = grid[0] + grid[4] + grid[8];
    slice[7] = grid[2] + grid[4] + grid[6];

    int x_pos_winning = 0;
    int o_pos_winning = 0;
    for (int i = 0; i < WINNIN_POS; i += 1) {
        if (slice[i] == -3) {
            return O_VAL;
        } else if (slice[i] == 3) {
            return X_VAL;
        } else if (slice[i] == -2) {
            if (x_pos_winning == 1) {
                return O_VAL;
            }
            x_pos_winning += 1;
        } else if (slice[i] == 2) {
            if (o_pos_winning == 1) {
                return X_VAL;
            }
            o_pos_winning += 1;
        }
    }
    return 0;
}

_Bool is_o_turn(int n) {
    return n % 2;
}

int main() {
    int grid[GRID_LEN] = {
        0, 0, 0,
        0, 0, 0,
        0, 0, 0
    };
    puts("Tic-Tac-Toe");

    int ply = 0;
    showgrid(grid);
    while (ply < 9) {
        char turn;
        int val;
        if (is_o_turn(ply)) {
            turn = 'o';
            val = O_VAL;
        } else {
            turn = 'x';
            val = X_VAL;
        }

        int p = prompt(ply, turn);
        if (p == -1) {
            puts("Value out of range!! Try again");
            continue;
        }
        if (grid[p-1] != 0) {
            printf("Square %d is occupied, try again\n", p);
            continue;
        }
        if (p == 0) {
            puts("Thanks for playing!!");
            return 0;
        }
        grid[p-1] = val;

        showgrid(grid);

        if (ply > 3) {
           int w = winner(grid);
            if (w == O_VAL) {
                puts(">>> O wins!");
                return 0;
            } else if (w == X_VAL) {
                puts(">>> X wins!");
                return 0;
            }
        }
        ply += 1;
    }
    puts("Cat's game!");

    return 0;
}
