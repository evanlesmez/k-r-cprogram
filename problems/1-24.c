#include <stdio.h>
/*
Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full generality.)
*/


int main(void){
    int c, prev_c = 0;
    unsigned int 
        line = 1,
        in_str = 0, 
        in_comment = 0,
        in_char = 0;
    unsigned int open_parantheses[100];
    unsigned int open_brackets[100];
    unsigned int open_braces[100];

    unsigned int 
        open_parantheses_i = 0, 
        open_brackets_i = 0, 
        open_braces_i = 0;

    unsigned int i;
    for (i =0; i < 100; ++i) {
        open_parantheses[i] = 0;
        open_braces[i] = 0;
        open_brackets[i] = 0;
    }

    while ((c=getchar()) != EOF){
        if (in_comment){
            if (c == '\n') {
                line++;
                in_comment = 0;
            }
        } else if (in_str){
            if (c == '"')
                in_str = 0;
        } else if (in_char) {
            if (c == '\'')
                in_char = 0;
        } else if (c == '"') {
            in_str = 1;
        } else if (c == '/') {
            if (prev_c == '/')
                in_comment = 1;
        } else if (c == '\'') {
            in_char = 1;
        } else if (prev_c == '\\'){
            // in escape sequnce
        } else if (c == '\n') {
            line ++;
        } else if (c == '(' ) {
            open_parantheses[open_parantheses_i] = line;
            open_parantheses_i++;
        } else if (c == ')') {
            if (open_parantheses_i == 0) {
                printf("Unmatched ')' at line: %d\n",line);
            }
            else {
                open_parantheses_i--;
                open_parantheses[open_parantheses_i] = 0;
            }
        } else if (c == '{' ) {
            open_brackets[open_brackets_i] = line;
            open_brackets_i++;
        } else if (c == '}') {
            if (open_brackets_i == 0) {
                printf("Unmatched '}' at line: %d\n",line);
            }
            else {
                open_brackets_i--;
                open_brackets[open_brackets_i] = 0;
            }
        } else if (c == '[' ) {
            open_braces[open_braces_i] = line;
            open_braces_i++;
        } else if (c == ']') {
            if (open_braces_i == 0) {
                printf("Unmatched ']' at line: %d\n",line);
            }
            else {
                open_braces_i--;
                open_braces[open_braces_i] = 0;
            }
        }
        prev_c = c;

    }
    for (i = 0; i < 100; i++){
        if (open_parantheses[i] > 0){
            printf("Unmatched '(' at line: %d\n", open_parantheses[i]);
        }
        if (open_brackets[i] > 0){
            printf("Unmatched '{' at line: %d\n", open_brackets[i]);
        }
        if (open_braces[i] > 0){
            printf("Unmatched '[' at line: %d\n", open_braces[i]);
        }
    }
    return 0;

}
