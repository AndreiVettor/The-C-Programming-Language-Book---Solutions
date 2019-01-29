#include <stdio.h>

int strrindex(char s[], char t);

int main(void)
{
    char s[] = "This is the string";

    
    printf("%d\n", strrindex(s, '!'));


    return 0;
}

int strrindex(char s[], char t)
{
    int i = 0;

    while(s[i++] != '\0');
    --i;

    while(i >= 0)
    {
        if(s[i] == t)
        {
            return i;
        }
        --i;
    }

    return -1;
}

