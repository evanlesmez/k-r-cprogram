#include <stdio.h>

// Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter? 

#define TABSTOP 4
// Chose symbolic parameter but a variable would be a good choice for handling cmd line args once I know how to do that

int main() 
{
    int col = 0, c;
    while ((c = getchar()) != EOF) {
        if (c == '\t'){
            int spaces = TABSTOP - (col % TABSTOP);
            for (int i=0; i < spaces; i++) putchar(' ');
            col += spaces;
        } else if (c == '\n') {
            putchar(c);
            col = 0;
        } else {
            putchar(c);
            col++;
        }
    }
    return 0;
}
