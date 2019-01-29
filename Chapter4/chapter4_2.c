#include <stdio.h>
#include <ctype.h>
#include <math.h>

float atof(char s[]);

int main(void)
{
    char s[] = "123.45e-6";

    printf("%e\n", atof(s));

    return 0;
}

float atof(char s[])
{
    unsigned int i = 0;
    int sign, expsign;
    double value, power, exppower;

    sign = (s[i] == '-') ? -1 : 1;

    if(s[i] == '-' || s[i] == '+')
    {
        ++i;
    }

    for(value = 0.0; isdigit(s[i]); ++i)
    {
        value = value * 10.0 + (s[i] - '0');
    }

    if(s[i] == '.')
    {
        ++i;
    }

    for(power = 1.0; isdigit(s[i]); ++i)
    {
        value = value * 10.0 + (s[i] - '0');
        power *= 10.0;
    }

    if(s[i] == 'e')
    {
        ++i;
    }

    if(s[i] == '-')
    {
        expsign = -1;
        ++i;
    }
    else
    {
        expsign = 1;
    }

    for(exppower = 0.0; isdigit(s[i]); ++i)
    {
        exppower = exppower * 10.0 + (s[i] - '0');
    }

    return sign * value / power * pow(10, expsign * exppower);
}