#include <stdio.h>

int main(int argc, char* argv[argc]) {
    char buffer[BUFSIZ];
    setbuf(stdout, buffer);
    printf("Type a letter:");
    int a = getchar();
    printf("Type a letter:");
    int b = getchar();

    printf("a='%c', b='%c'", a, b);

    return 0;
}
