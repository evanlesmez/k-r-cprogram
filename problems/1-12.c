# include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0

int main() {
    int c, state;
    while ((c = getchar()) != EOF) {

        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN_WORD) {
                putchar('\n');
            }
        state = OUT_WORD;
        } 
        else {
            putchar(c);
            state = IN_WORD;
        }
    }
    return 0;
}
