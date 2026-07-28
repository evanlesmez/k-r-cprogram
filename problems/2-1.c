#include <stdio.h>
#include <limits.h>
#include <float.h>

/*
    See appendix B.11
    Exercise 2-1. 
    Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. 
    Harder if you compute them: determine the ranges of the various floating-point types.
*/

int main (){
    printf("Char range is %d to %d\n",CHAR_MIN,CHAR_MAX);
    printf("Short range is %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Int range is %d to %d\n",INT_MIN,INT_MAX);
    printf("Long range is %ld to %ld \n", LONG_MIN,LONG_MAX);

    printf("UChar range is %d to %d\n",0,UCHAR_MAX);
    printf("UShort range is %d to %d\n", 0, USHRT_MAX);
    printf("UInt range is %u to %u\n",0,UINT_MAX);
    printf("ULong range is %u to %lu\n", 0, ULONG_MAX);
    printf("Float range is %e to %e\n",FLT_MIN, FLT_MAX);
    printf("Double range is %e to %e\n",DBL_MIN, DBL_MAX);
    return 0;
}
