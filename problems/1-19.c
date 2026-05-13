#include <stdio.h>
// Exercise 1-19. Write a function reverse(s) that reverses the character string s.
// Use it to write a program that reverses its input a line at a time. 

#define MAXLINE 1000

int readline (char line [], int maxline);
void copy(char to[], char[]);
void reverse (char line [], int len);
int main() 
{
    int len;
    char line[MAXLINE];

    while ((len = readline(line, MAXLINE)) > 0) {
        reverse(line, len);
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
void reverse (char line [], int len)
{
    if (len < 3) return;
    int i;
    char c;

    i = 0;
    while (i < (len - 2)/2)
    {
        c = line[i];
        line[i] = line[len - 2 - i];
        line[len - 2 - i] = c;
        ++i;
    }
}
