#include <stdio.h>

// Print a histogram of the lengths of words in its input
#define IN_WORD 1
#define OUT_WORD 0

int main() {
    int c, i, state, nc;
    int l_words[15]; 

    nc = 0;
    for (i = 1; i < 16; i++)
        l_words[i] = 0;

    while ((c = getchar()) != EOF) {
        // if whitespace
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN_WORD) {
                // just ended a word so add the length of it to array
                ++l_words[nc];
                nc = 0;
            }
            state = OUT_WORD;
        }
        else {
            ++nc;
            state = IN_WORD;
        }
    }
    printf("\nWord Length Histogram\n\n");
    for (i = 1; i < 16; i++) {
        printf("%d ", i);
        for (int j =0; j < l_words[i]; ++j) 
            putchar('-');
        putchar('\n');
    }
    return 0;
}
