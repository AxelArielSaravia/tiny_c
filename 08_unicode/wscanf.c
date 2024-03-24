#include <wchar.h>
#include <locale.h>

#define pound 0xa3
int main() {
    int quantity;

    setlocale(LC_CTYPE, "en_US.utf8");

    wprintf(L"How many crisps do you want?");
    wscanf(L"%d", &quantity);

    float total = (float)quantity * 1.4;
    wprintf(L"That'll be %lc%.2f\n", pound, total);

    return 0;
}
