#include <wchar.h>
#include <stdio.h>

int main() {
    wchar_t yen = L'¥';
    wchar_t hello[] = L"Hello, wide world!";
    wprintf(L"%ls\n", hello);
    return 0;
}
