#include <locale.h>
#include <wchar.h>

int main() {
    setlocale(LC_CTYPE, "en_US.utf8");
    wchar_t s[] = L"I ? to code\n";
    s[2] = L'♥';
    wprintf(L"%ls", s);
    return 0;
}
