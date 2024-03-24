#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#define BUFF_SIZE 32
int main() {
    setlocale(LC_CTYPE, "en_US.utf8");
    wchar_t input[BUFF_SIZE];

    wprintf(L"Type some fancy text: ");
    fgetws(input, BUFF_SIZE, stdin);
    wprintf(L"You typed: '%ls'\n", input);

    return 0;
}
