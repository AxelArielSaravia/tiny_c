#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#define BUFF_SIZE 32
int main() {
    setlocale(LC_CTYPE, "en_US.utf8");
    wchar_t input[BUFF_SIZE];

    wprintf(L"Type some fancy text: ");
    fgetws(input, BUFF_SIZE, stdin);

    for (int i = 0; i < BUFF_SIZE && input[i] != 0; i += 1) {
        if (input[i] == '\n') {
            input[i] = 0;
            break;
        }
    }

    wprintf(L"You typed: '%ls'\n", input);

    return 0;
}
