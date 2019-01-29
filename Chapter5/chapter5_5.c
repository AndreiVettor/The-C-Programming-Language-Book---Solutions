#include <stdio.h>

void strncpy(char *s, char *t, unsigned int n);
void strncat(char *s, char *t, unsigned int n);
int strncmp(char *s, char *t, unsigned int n);
unsigned int strlen(char *s);

int main(void)
{
    char s[100] = "Hello, world!";
    char t[100] = "Look at me!";

    strncpy(s, t, 6);
    printf("%s\n", s);

    strncat(s, t, 6);
    printf("%s\n", s);

    printf("%d\n", strncmp(s, t, 6));

    return 0;
}

void strncpy(char *s, char *t, unsigned int n)
{
    while((*s++ = *t++) != '\0' && --n)
        ;
}

void strncat(char *s, char *t, unsigned int n)
{
    s = s + strlen(s);
    while(*t != '\0' && n--)
    {
        *s++ = *t++;
    }
}

int strncmp(char *s, char *t, unsigned int n)
{
    while(*s++ == *t++ && --n)
    {
        if(*s == '\0')
            return 0;
    }
    
    return *s - *t;
}

unsigned int strlen(char *s)
{
    unsigned int n = 0;

    while(*s++ != '\0')
        ++n;

    return n;
}