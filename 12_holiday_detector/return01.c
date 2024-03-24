#include <stdlib.h>

int main(int argc, char* argv[argc]) {
    if (argc > 1) {
        return strtol(argv[1], (void*)0, 10);
    } else {
        return 0;
    }
}
