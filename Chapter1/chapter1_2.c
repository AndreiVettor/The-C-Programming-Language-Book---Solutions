#include <stdio.h>

int main() 
{
    float fahr, celsius;
    int lower, upper, step;

    /* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */

    lower = 0; // lower limit of temperature table
    upper = 300; // upper limit
    step = 20; // step size

    fahr = lower;
    printf("%s %s\n", "*F", "*C");
    while(fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    /* print Celsius - Fahrenheit table
    for celsius = 0, 20, ..., 300; floating-point version */

    lower = 0; // lower limit of temperature table
    upper = 300; // upper limit
    step = 20; // step size

    celsius = lower;
    printf("\n%s %s\n", "*C", "*F");
    while(celsius <= upper)
    {
        fahr = (9.0 / 5.0 * celsius) + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}