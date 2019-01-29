#include <stdio.h>

void strcat(char *s, char *t);
unsigned int strlen(char *s);

int main(void)
{
    char s[100] = "This is the string";
    char t[100] = ", yes!";

    strcat(s, t);

    printf("%s\n", s);

    return 0;
}

void strcat(char *s, char *t) 
{
    int end;

    end = strlen(s);

    while(*t != '\0')
    {
        *(s++ + end) = *t++;
    }
}

unsigned int strlen(char *s)
{
    unsigned int n = 0;

    while(*s++ != '\0')
        ++n;

    return n;
}