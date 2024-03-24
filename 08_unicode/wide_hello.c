#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_CTYPE, "en_US.utf8");
    wchar_t russian[] = {0x41f, 0x440, 0x438, 0x432, 0x435, 0x442, '!', '\n', 0};
    wchar_t chinese[] = {0x4f31, 0x597d, '\n', 0};
    wchar_t emoji[] = {0x1f44b, '\n', 0};
    fputws(russian, stdout);
    fputws(chinese, stdout);
    fputws(emoji, stdout);
    return 0;
}
