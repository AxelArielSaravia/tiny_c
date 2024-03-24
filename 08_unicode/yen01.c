#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_CTYPE, "en_US.utf8");
    wchar_t yen = L'¥';
    wprintf(L"That will be %lc500\n", yen);
    return 0;
}
