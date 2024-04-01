#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int prompt(char const sym) {
    printf("%c's turn: Pick a square, 0 to quit: ", sym);

    int square = -1;
    scanf("%d", &square);

    if (square < 0 || square > 9) {
        return -1;
    }

    return square;
}

#define SLICES_LEN 8
int const SLICES[SLICES_LEN][3] = {
    {0,1,2}, //horizontal top
    {3,4,5}, //horizontal mid
    {6,7,8}, //horizontal bottom
    {0,3,6}, //vertical left
    {1,4,7}, //vertical mid
    {2,5,8}, //vertical right
    {0,4,8}, //diagonal top left
    {2,4,6}  //diagonal top right
};

#define computer_MSG "%c's turn: The computer moves to square %d\n"

int computer(int ply, int val, char const sym, int grid[GRID_LEN]) {
    int position = -1;

    if (rand() % 6 < 5 && (ply == 0 || (ply < 3 && grid[4] == 0))) {
        position = 5;
        printf(computer_MSG, sym, position);
        return position;
    }

    if (rand() % 3 < 2 && ply < 3) {
        int len = 0;
        int corners[4] = {0};
        if (grid[0] == 0) {
            corners[len] = 1;
            len += 1;
        }
        if (grid[2] == 0) {
            corners[len] = 3;
            len += 1;
        }
        if (grid[6] == 0) {
            corners[len] = 7;
            len += 1;
        }
        if (grid[8] == 0) {
            corners[len] = 9;
            len += 1;
        }
        if (len > 0) {
            int r = rand() % len;
            position = corners[r];
            printf(computer_MSG, sym, position);
            return position;
        }
    }

    int op_val;
    if (val == O_VAL) {
        op_val = X_VAL;
    } else {
        op_val = O_VAL;
    }

    for (int i = 0; i < SLICES_LEN; i += 1) {
        int a = SLICES[i][0];
        int b = SLICES[i][1];
        int c = SLICES[i][2];

        //searching to winn moves
        if (grid[a] + grid[b] + grid[c] == val * 2) {
            if (grid[a] == 0) {
                position = a + 1;
            } else if (grid[b] == 0) {
                position = b + 1;
            } else {
                position = c + 1;
            }
            printf(computer_MSG, sym, position);
            return position;
            //searching to blocks moves
        } else if (grid[a] + grid[b] + grid[c] == op_val * 2) {
            if (grid[a] == 0) {
                position = a + 1;
            } else if (grid[b] == 0) {
                position = b + 1;
            } else {
                position = c + 1;
            }
            printf(computer_MSG, sym, position);
            return position;
            //regular moves
        }
    }
    position = rand() % GRID_LEN;
    while (grid[position] != 0) {
        position = rand() % GRID_LEN;
    }
    position += 1;

    printf(computer_MSG, sym, position);
    return position;
}

int winner(int grid[GRID_LEN], int turn_val) {
    int x_pos_winning = 0;
    int o_pos_winning = 0;
    for (int i = 0; i < SLICES_LEN; i += 1) {
        int slice_sum = 0;
        {
            int a = SLICES[i][0];
            int b = SLICES[i][1];
            int c = SLICES[i][2];
            slice_sum = grid[a] + grid[b] + grid[c];
        }
        if (turn_val == X_VAL && slice_sum == O_VAL * 2) {
            return O_VAL;
        }
        if (turn_val == O_VAL && slice_sum == X_VAL * 2) {
            return X_VAL;
        }
        if (slice_sum == O_VAL * 3) {
            return O_VAL;
        } else if (slice_sum == X_VAL * 3) {
            return X_VAL;
        } else if (slice_sum == O_VAL * 2) {
            if (x_pos_winning > 0 && turn_val == O_VAL) {
                return O_VAL;
            }
            x_pos_winning += 1;
        } else if (slice_sum == X_VAL * 2) {
            if (o_pos_winning > 0 && turn_val == X_VAL) {
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

#define FORMAT "ttt [(0,1,2)|-p|--player (0,1,2)]\n"

int main(int argc, char const* argv[argc]) {
    int players = 0;

    {//Flags
        int pp = -1;
        if (argc == 2) {
            pp = atoi(argv[1]);
        } else if (argc == 3 && (strcmp(argv[1], "-p") == 0 || strcmp(argv[1], "--players"))) {
            pp = atoi(argv[2]);
        } else {
            pp = 0;
        }
        if (pp != 0 && pp != 1 && pp != 2) {
            fprintf(stderr, FORMAT);
            return 1;
        }
        players = pp;
    }

    srand((unsigned)time((void*)0));

    puts("Tic-Tac-Toe");

    int grid[GRID_LEN] = {0};

    int computer_val;
    if (rand() % 2 == 1) {
        computer_val = O_VAL;
    } else {
        computer_val = X_VAL;
    }

    int turn_val;
    char turn_sym;
    if (rand() % 2 == 1) {
        turn_val = X_VAL;
        turn_sym = 'x';
    } else {
        turn_val = O_VAL;
        turn_sym = 'o';
    }

    showgrid(grid);

    int ply = 0;
    while (ply < 9) {
        int position;
        if (players == 0) {
            position = computer(ply, turn_val, turn_sym, grid);
        } else if (players == 1) {
            if (turn_val == computer_val) {
                position = computer(ply, turn_val, turn_sym, grid);
            } else {
                position = prompt(turn_sym);
            }
        } else {
            position = prompt(turn_sym);
        }

        if (position == 0) {
            puts("Thanks for playing!!");
            return 0;
        }

        if (position == -1) {
            puts("Value out of range!! Try again");
            continue;
        }
        if (grid[position - 1] != 0) {
            printf("Square %d is occupied, try again\n", position);
            continue;
        }

        grid[position - 1] = turn_val;

        showgrid(grid);

        if (ply > 3) {
            int w = winner(grid, turn_val);
            if (w == O_VAL) {
                puts(">>> O wins!");
                return 0;
            } else if (w == X_VAL) {
                puts(">>> X wins!");
                return 0;
            }
        }

        ply += 1;
        if (turn_val == X_VAL) {
            turn_sym = 'o';
            turn_val = O_VAL;
        } else {
            turn_sym = 'x';
            turn_val = X_VAL;
        }
    }
    puts("Cat's game!");

    return 0;
}
