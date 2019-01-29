#include <stdio.h>

void itoa(int x, char s[]);

int main(void)
{
    char s[100];
    int x = 255;

    itoa(x, s);
    printf("%s\n", s);

    return 0;
}

void itoa(int x, char s[])
{
    static int i = 0;

    if(x / 10)
    {
        itoa(x / 10, s);
    }
    s[i++] = x % 10 + '0';
    s[i+1] = '\0';
}