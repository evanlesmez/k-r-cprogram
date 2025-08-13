#include <stdio.h>

// Print a histogram of the lengths of words in its input

int main() {
    unsigned int c,i, nwhite;
    int nchar[255]; 

    nwhite = 0;
    for (i=0; i<256; i++) {
        nchar[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        // NOTE: evan - using (char) cast is kind of cheating because not taught in book yet.
        // Instead could have been clever and copied the subtraction method for digits to cast to char.
        // e.g lower-case letter subtract c - 'a'
        // 'a' is 97 to 'z' 122 'A' is 65 to 'Z' is 90

        if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else {
            ++nchar[c];
        }
    }
    printf("\nchar frequency histogram\n");
    for (i = 0; i < 256; i++) {
        if (nchar[i] < 1)
        {
            continue;
        }
        printf("%c ", (char) i);
        for (int j =0; j < nchar[i]; ++j) 
            putchar('-');
        putchar('\n');
    }
    printf("whitespace ");
    for (i = 0; i < nwhite; ++i) 
            putchar('-');
    putchar('\n');

    return 0;
}
