#include <stdio.h>
#include <locale.h>

int main() {
    char* locale = setlocale(LC_ALL, "");
    printf("The current locale is %s\n", locale);
    return 0;
}
