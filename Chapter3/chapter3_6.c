#include <stdio.h>
#include <math.h>
#include <string.h>

void itoa(int n, char str[], int minwidth);
void reverse(char s[]);

int main(void)
{
    char s[100];

    itoa(-125, s, 8);

    printf("%s\n", s);

    return 0;
}

void itoa(int n, char str[], int minwidth)
{
    int i = 0, sign;
    
    if((sign = n) < 0)
    {
        // Because converting -(2^(wordsize - 1)) would produce an
        // overflow we have to manually convert the last figure of
        // our number, n
        if(n == (int)(-pow(2, (sizeof(int) * 8))))
        {
            // eg. -128 would turn into 127
            n = -(n + 1);

            // Add 1 to 7 and put it into the string
            str[i++] = (n % 10 + 1) + '0';

            // Move to the next position
            n /= 10;
        }
        else 
        {
            n = -n;
        }
    }
    
    do {
        str[i++] = n % 10 + '0';
    } while((n /= 10) > 0);

    if(sign < 0)
    {
        str[i++] = '-';
    }

    while(i < minwidth)
    {
        str[i++] = ' ';        
    }

    str[i] = '\0';

    reverse(str);
}

void reverse(char str[])
{
    unsigned int i = 0, j = 0, n = 0;
    char c;

    while(str[j++] != '\0');
    // Roll j back to the last character and set n to 
    j -= 2;
    n = j + 1;

    for(i = 0; j > n/2, i < n/2; ++i, --j)
    {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}