#include <stdio.h>
#include "mystr.h"

int main() {
    char string[] = "The great american novel";
    strcap(string);
    printf("%s\n", string);
    return 0;
}
