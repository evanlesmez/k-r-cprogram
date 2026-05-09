#include <stdio.h>
// Write a program to print all input lines that are longer than 80 characters. 
//
#define MAXLINE 1000

int readline (char line [], int maxline);
void copy(char to[], char[]);
int main() 
{
    int len;
    char line[MAXLINE];

    while ((len = readline(line, MAXLINE)) > 0)
        if (len > 80) {
            printf("len:%d | %s", len, line);
        }
    return 0;
}

/* readline: read a line into s, return length */
int readline(char s[], int lim)
{
    int c, i;
    for (i=0; (c=getchar()) !=EOF && c!='\n'; ++i)
        // without lim - 2 will overflow on limit sized line b/c of \n and \0 char appended at end
        if (i < lim-2) {
            s[i] = c;
        }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
