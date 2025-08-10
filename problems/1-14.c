#include <stdio.h>

// Print a histogram of the lengths of words in its input

int main() {
    int c, i, nwhite;
    int nchar[255]; 

    nwhite = 0;
    for (i = 0; i < 255; i++) 
    {
        nchar[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        // Use this line below to debug the int values of chars to ints
        printf("%c == %i =? %i \n", c, c, c-'0');
        // a is 97 to z 122 
        // A is 65 to Z is 90
        // Actually could just make an array of ints that is one byte large to match the size of char
        // Then just convert from that in printf
        ++nchar[c-'0'];
        if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
    }
//    printf("\nChar frequency histogram\n\n");
//    for (i = 0; i < 36; i++) {
//        printf("char: %c ", i);
//        for (int j =0; j < nchar[i]; ++j) 
//            putchar('-');
//        putchar('\n');
//    }
    return 0;
}
