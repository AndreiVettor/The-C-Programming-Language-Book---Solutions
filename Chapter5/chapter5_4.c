#include <stdio.h>
#include <string.h>

unsigned int strend(char *s, char *t);

int main(void)
{
    char s[100] = "This book is really cool";
    char t[100] = "is really cool";

    printf("%d\n", strend(s, t));    

    return 0;
}

unsigned int strend(char *s, char *t)
{
    unsigned int ssize = strlen(s);
    unsigned int tsize = strlen(t);
    
    unsigned int n = 0;

    while(*(s-- + ssize) == *(t-- + tsize) && n < tsize)
    {
        ++n;
    }

    if(n == tsize)
        return 1;

    return 0;
}

// Improvements:
// Checking out of bounds for the beginning of the string