#include <stdio.h>

// Write a program to count blanks, tabs, and newlines
int main() {
    int c;
    int cnt_blanks = 0, cnt_tabs = 0, cnt_newlines = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ':
                ++cnt_blanks;
                break;
            case '\t':
                ++cnt_tabs;
                break;
            case '\n':
                ++cnt_newlines;
                break;
        }
    }

    printf("blank space: %d\ttabs: %d\t new linews: %d", cnt_blanks, cnt_tabs, cnt_newlines);
    return 0;
}
