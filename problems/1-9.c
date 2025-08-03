#include <stdio.h>

// Write a program to convert spcaes in input to output
int main() {
    int c, prevc;
    while ((c = getchar()) != EOF) {
        if (c != ' ' || (c == ' ' && prevc != ' ')) putchar(c);
        prevc = c;
    }

    return 0;
}
