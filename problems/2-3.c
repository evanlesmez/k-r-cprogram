#include <math.h>
#include <stdio.h>
#include <ctype.h>
/*
Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F.
*/

int htoi(char s[]) {
    int i,n, base, start;
    n = 0;
    i = 0;
    base = 1;

    if(i < 2 && s[0] == '0' && tolower(s[1]) == 'x')
        i = 2;
    
    while(1){
        int lc = tolower(s[i]);
        if (isdigit(s[i]))
        {
            n = n + base * (s[i] - '0');
        }
        else if (lc >= 'a' && lc <= 'f')
        {
            n = n + base * (10 + lc - 'a');
        }
        else 
            break;

        base *= 16;
        i++;
    }
    return n;
}

int main(){
    printf("Hex: %s\tExpected: 16\t Return: %d \n", "0x01", htoi("0x01"));
    printf("Hex: %s\tExpected: 257\t Return: %d \n", "0x101", htoi("0x101"));
    printf("Hex: %s\tExpected: 3885\t Return: %d \n", "0Xd2f", htoi("0Xd2f"));
    printf("Hex: %s\tExpected: 3885\t Return: %d \n", "0xD2F", htoi("0XD2F"));
    printf("Hex: %s\tExpected: 0\t Return: %d \n", "x123", htoi("x123"));
    printf("Hex: %s\tExpected: 0\t Return: %d \n", "0xword", htoi("0xword"));
    printf("Hex: %s\tExpected: 0\t Return: %d \n", "w12ord", htoi("w12ord"));
    return 0;
}
