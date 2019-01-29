#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main(void)
{
    char s[100] = "Salut mai!";

    reverse(s);

    printf("%s\n", s);

    return 0;
}

void reverse(char s[])
{
    static int i = 0;

    // Swap
    char temp = s[i];
    s[i] = s[strlen(s) - 1 - i];
    s[strlen(s) - 1 - i] = temp;

    ++i;

    if(i <= strlen(s) - 1 - i)
    {
        reverse(s);
    }
}