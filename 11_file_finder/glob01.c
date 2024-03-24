#include <stdio.h>

int main(int argc, char const* argv[argc]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i += 1) {
            printf("%s\n", argv[i]);
        }
    }
    return 0;
}
