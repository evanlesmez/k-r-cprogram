#include <stdio.h>

//NOTE: pg.19 - Verify that the expression getchar () != EOF is 0 or 1
int main() {
    int c;
    printf("%d\n", EOF);
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    return 0;
}

