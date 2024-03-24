#include <stdio.h>
#include <ctype.h>

char const* nato[] = {
    "Alfa",
    "Bravo",
    "Charlie",
    "Delta",
    "Echo",
    "Foxtrot",
    "Golf",
    "Hotel",
    "India",
    "Juliett",
    "Kilo",
    "Lima",
    "Mike",
    "November",
    "Oscar",
    "Papa",
    "Quebec",
    "Romeo",
    "Sierra",
    "Tango",
    "Uniform",
    "Victor",
    "Whiskey",
    "Xray",
    "Yankee",
    "Zulu"
};

#define SIZE 64
int main(int argc, char* argv[argc]) {
    char phrase[SIZE];
    char ch;
    printf("Enter a word or phrase: ");
    fgets(phrase, SIZE, stdin);
    for (int i = 0; phrase[i] && i < SIZE; i += 1) {
        ch = toupper(phrase[i]);
        if (isalpha(ch)) {
            printf("%s ", nato[ch - 'A']);
        }
    }
    putchar('\n');
    return 0;
}
