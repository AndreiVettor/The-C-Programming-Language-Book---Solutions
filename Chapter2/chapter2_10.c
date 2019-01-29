#include <stdio.h>

void lower(char str[]);

int main(void)
{
    char str[] = "UpPer";

    lower(str);

    printf("%s\n", str);

    return 0;
}

void lower(char str[])
{
    unsigned int i = 0;

    while(str[i] != '\0')
    {
        str[i] = (str[i] < 'a') ? str[i] + ('a' - 'A') : str[i];
        ++i;
    }
}