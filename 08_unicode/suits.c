#include <wchar.h>
#include <locale.h>

#define count 4
int main() {
    setlocale(LC_CTYPE, "en_US.utf8");
    wchar_t suits[count] = {0x2660, 0x2665, 0x2663, 0x2666};
    for (int x = 0; x < count; x += 1) {
        putwchar(suits[x]);
    }
    putwchar('\n');
    return 0;
}
