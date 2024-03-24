#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_CTYPE, "en_US.utf8");
    wchar_t s[] = L"That will be ?500\n";
    s[13] = L'¥';
    wprintf(L"%ls", s);
    return 0;
}
