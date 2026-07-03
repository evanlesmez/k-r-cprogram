#include <stdio.h>
/* Exercise 1-22   
Write a program to 'fold' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.
*/

/*
 Example.
 this line should fold after here.
 Or in the middle of sentence like
 here
*/


#define MAXLINE 1000
#define FOLD_LEN 80
#define TABSTOP 4

char line[MAXLINE];
int readline(void);

int main() 
{
    int i, len;
    int col, last_blank_idx;
    while ((len = readline()) > 0)
    {
        if(len >= FOLD_LEN)
        {
            i = 0;
            col = 0;
            while(i<len)
            {
                if(line[i] == ' ' || line[i] == '\t')
                    last_blank_idx = i;

                if(col == FOLD_LEN)
                {
                    line[last_blank_idx] = '\n';
                    col = 0;
                }
                col++;
                i++;
            }
        }
        printf("%s", line);
    }
    return 0;
}

int readline(void)
{
    int c, i;
    extern char line[];

    for ( i=0; i<MAXLINE-1 && ( c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if(c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
