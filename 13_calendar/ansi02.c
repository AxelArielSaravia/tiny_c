#include <stdio.h>

#define FOREGROUND_BLACK    "\x1b[30m"
#define FOREGROUND_RED      "\x1b[31m"
#define FOREGROUND_GREEN    "\x1b[32m"
#define FOREGROUND_YELLOW   "\x1b[33m"
#define FOREGROUND_BLUE     "\x1b[34m"
#define FOREGROUND_MAGENTA  "\x1b[35m"
#define FOREGROUND_CYAN     "\x1b[36m"
#define FOREGROUND_WHITE    "\x1b[37m"

#define BACKGROUND_BLACK    "\x1b[40m"
#define BACKGROUND_RED      "\x1b[41m"
#define BACKGROUND_GREEN    "\x1b[42m"
#define BACKGROUND_YELLOW   "\x1b[43m"
#define BACKGROUND_BLUE     "\x1b[44m"
#define BACKGROUND_MAGENTA  "\x1b[45m"
#define BACKGROUND_CYAN     "\x1b[46m"
#define BACKGROUND_WHITE    "\x1b[47m"

#define RESET "\x1b[0m"

int main() {
    printf("%sHello%s Black\n", FOREGROUND_BLACK, RESET);
    printf("%sHello%s Red\n", FOREGROUND_RED, RESET);
    printf("%sHello%s Green\n", FOREGROUND_GREEN, RESET);
    printf("%sHello%s Yellow\n", FOREGROUND_YELLOW, RESET);
    printf("%sHello%s Blue\n", FOREGROUND_BLUE, RESET);
    printf("%sHello%s Magenta\n", FOREGROUND_MAGENTA, RESET);
    printf("%sHello%s Cyan\n", FOREGROUND_CYAN, RESET);
    printf("%sHello%s White\n", FOREGROUND_WHITE, RESET);

    printf("%sHello%s Black\n", BACKGROUND_BLACK, RESET);
    printf("%sHello%s Red\n", BACKGROUND_RED, RESET);
    printf("%sHello%s Green\n", BACKGROUND_GREEN, RESET);
    printf("%sHello%s Yellow\n", BACKGROUND_YELLOW, RESET);
    printf("%sHello%s Blue\n", BACKGROUND_BLUE, RESET);
    printf("%sHello%s Magenta\n", BACKGROUND_MAGENTA, RESET);
    printf("%sHello%s Cyan\n", BACKGROUND_CYAN, RESET);
    printf("%s%sHello%s White\n", BACKGROUND_WHITE, FOREGROUND_BLACK, RESET);

    return 0;
}
