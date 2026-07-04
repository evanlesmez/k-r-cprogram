#include <stdio.h>
/*
 Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.
*/
/* 
  look for // but not if inside str or inside comment
*/
// This normal comment should be omitted by program as well as top comments
int main(void){
    char x[20] = "// /* /* */ SUCCESS";
    int c, prev_c = 0;
    unsigned int 
        in_str = 0, 
        in_comment = 0, 
        in_multiline_comment = 0,
        just_exited_multiline = 0;
    int r = 5 / 1;
    int z = 5 * 1;
    while ((c = getchar()) != EOF)
    {
        if (c == '"')
            in_str = !in_str;

        if(in_str){
            putchar(c);
        }
        else if(in_comment){
            if(c == '\n'){
                in_comment = 0;
            }
        }
        else if(in_multiline_comment){
            if(prev_c == '*' && c == '/'){
                in_multiline_comment = 0;
                just_exited_multiline = 1;
            }
        }
        else if(just_exited_multiline){
            just_exited_multiline = 0;
        }
        else if(c == '/'){
            // never putchar c until proven next c is not /
            // We only move left to right through chars
            if(prev_c == '/')
                in_comment = 1;
        }
        else if(c == '*'){
            if(prev_c == '/')
                in_multiline_comment = 1;
            else {
                putchar(c);
            }
        }
        else if((prev_c == '/' && c != '/')){
            putchar(prev_c);
            putchar(c);
        }
        else 
            putchar(c);

        prev_c = c;
    }
    return 0;
}


