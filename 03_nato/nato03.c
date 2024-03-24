#include <stdio.h>
#include <string.h>

#define W_SIZE 64
int main(int argc, char* argv[argc]) {
    printf("Type some text: ");

    char sometext[W_SIZE];
    fgets(sometext, W_SIZE, stdin);

    char* match = strtok(sometext, " ");
    while (match) {
        printf("%s\n", match);
        match = strtok(0, " ,.!?:;\"'");
    }
    return 0;
}
