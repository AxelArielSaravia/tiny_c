#include <stdio.h>

char const*const Morse_Digit[] = {
    "-----", /*0*/
    ".----",
    "..---",
    "...--",
    "....-",
    ".....",
    "-....",
    "--...",
    "---..",
    "----.",
};

char const*const Morse_Alpha[] = {
    ".-",   /*A*/
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--.."
};

void toMorse(char c) {
    if ('a' <= c && c <= 'z') {
        printf("%s ", Morse_Alpha[c - 'a']);
    } else if ('A' <= c && c <= 'Z') {
        printf("%s ", Morse_Alpha[c - 'A']);
    } else if ('0' <= c && c <= '9') {
        printf("%s ", Morse_Digit[c - '0']);
    } else if (c == ' ' || c == '\n' || c == '\t') {
        putchar('\n');
    }
}

int main() {
    return 0;
}
