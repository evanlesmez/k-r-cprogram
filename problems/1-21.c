#include <stdio.h>

// Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?

// a blank space should be used when one char needed

#define TABSTOP 4

// could keep the lats TABSTOP length chars in array.  
// could track last blank
// 
// cases:
// last blank is > 1 ago and reached end -> rm current blank and putchar 1 /t
// last blank is this char and end -> keep all
//
// Only need to put a tab after a non blank character before tabstop hit when more than 1 blank between non-blank char and tabstop

int main() 
{
    int col = 1, c, since_last_blank = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' '){
            if (col % TABSTOP == 0){
                // at tabstop
                if (since_last_blank > 1) {
                    putchar('\t');
                    since_last_blank = 0;
                } else {
                    putchar(c);
                }
            } else {
                since_last_blank++;
            }
            col++;
        } else {
            for (int i=0; i < since_last_blank; i++) putchar(' ');
            putchar(c);
            since_last_blank = 0;
            if (c == '\n') {
                col = 1;
            } else {
                col++;
            }
        } 
    }
    return 0;
}
