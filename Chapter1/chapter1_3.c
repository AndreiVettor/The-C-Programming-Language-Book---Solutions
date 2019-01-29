#include <stdio.h>

/* print Fahrenheit-Celsius table */

#define LOWER 0
#define HIGHER 300
#define STEP 20

void main()
{
    int fahr;

    for (fahr = HIGHER; fahr > LOWER; fahr = fahr - STEP)
    {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}