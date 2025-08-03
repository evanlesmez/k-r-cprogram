#include <stdio.h>

// Write a program to convert each tab, backspace, and backslash by their printf equivalent value 
int main() {
    int c;
    while ((c = getchar()) != EOF) {
        switch(c){
            case '\b':
                printf("\\b");
                break;
            case '\t':
                printf("\\t");
                break;
            case '\\':
                printf("\\");
                break;
            default:
                putchar(c);
        }
    }
    return 0;
}
