#include <stdio.h>
// Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines. 
//
#define MAXLINE 1000

int readline (char line [], int maxline);
void copy(char to[], char[]);
int trimline (char line [], int len);
int main() 
{
    int len, trimmedlen;
    char line[MAXLINE];

    while ((len = readline(line, MAXLINE)) > 0) {
        trimmedlen = trimline(line, len);
        if (trimmedlen < 3) {
            continue;
        }
        printf("%s", line);
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
int trimline (char line [], int len)
{
    // loop backwards from \n. Replace chars with \0 until non-tab or space found.
    int c, i;
    for (i=len - 3; (c=line[i]) == '\t' || c == ' ';  i--){
        line[i] = '\n';
        line[i + 1] = '\0';
        line[i + 2] = 0;
    }
    return i + 3;
}
