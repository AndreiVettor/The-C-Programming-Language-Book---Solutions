#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 1000

int htoi(char str[]);
unsigned int getln(char str[], unsigned int limit);

int main(void)
{
    char line[MAX_LENGTH];

    getln(line, MAX_LENGTH);

    printf("%d\n", htoi(line));

    return 0;
}

int htoi(char str[])
{
    unsigned int i, unit = 0, number = 0;

    for(i = strlen(str) - 2; i >= 0; --i)
    {
        if(str[i] >= '0' && str[i] <= '9')
            unit = str[i] - '0';
        else if(str[i] >= 'a' && str[i] <= 'f')
            unit = str[i] - 'a' + 10;
        else if(str[i] >= 'A' && str[i] <= 'F')
            unit = str[i] - 'A' + 10;
        else if((str[i] == 'x' || str[i] == 'X') && str[i-1] == '0')
            return number;

        printf("Unit: %d\n", unit);

        number += unit * pow(16, strlen(str) - 2 - i);
    }

    return number;
}

unsigned int getln(char str[], unsigned int limit)
{
    char c;
    unsigned int i = 0;

    while((c = getchar()) != EOF && c != '\n' && i < limit)
    {
        str[i++] = c;
    }

    if(c == '\n')
    {
        str[i++] = '\n';
    }

    str[i] = '\0';

    return i;
}