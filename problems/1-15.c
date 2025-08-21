#include <stdio.h>

// Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.  

float fahr_to_celsius (float temp)
{
    return  (5.0/9.0) * (temp -32.0);
}
int main() 
{
    int lower, upper, step;
    float fahr, celsius;

    lower = 0;
    upper = 220;
    step = 10;
    
    fahr = lower;
    printf("Fahr\tC\n");
    while (fahr <= upper) {
        celsius = fahr_to_celsius(fahr);
        printf("%.0f\t%.2f\n", fahr, celsius);
        fahr += step;
    }
    return 0;
}
