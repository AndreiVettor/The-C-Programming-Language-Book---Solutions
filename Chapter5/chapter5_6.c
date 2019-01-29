#include <stdio.h>

void getln(char *s);
int atoi(char *s);
void itoa(char *s, int n);
unsigned int strlen(char *s);
void reverse(char *s);
int strindex(char *s, char *t);
int getop(char *s);

int main(void)
{
    char s[100] = "programming is cool";
    char t[100] = "cool";
    char o[100];

    printf("strindex: %d\n", strindex(s, t));

    getln(s);
    
    printf("getln: %s\n", s);
    
    int n = atoi(s);
    printf("atoi: %d\n", n);

    itoa(s, n);
    printf("itoa: %s\n", s);

    printf("getop: %d", getop(o));

    return 0;
}

void getln(char *s)
{
    while((*s = getchar()) != EOF && *s != '\n')
    {
        ++s;
    }

    *s = '\0';
}

int atoi(char *s)
{
    int n = 0;

    while(*s != '\0')
    {
        n = n * 10 + *s - '0';
        ++s;
    }

    return n;
}

void itoa(char *s, int n)
{
    char *p = s;

    while(n)
    {
        *(p++) = n % 10 + '0';

        n /= 10;
    }

    *(p) = '\0';

    reverse(s);
}

unsigned int strlen(char *s)
{
    unsigned int n = 0;

    while(*s++ != '\0')
        ++n;

    return n;
}

void reverse(char *s)
{
    char aux;
    char *p = s + strlen(s) - 1;

    while(s - p < 0)
    {
        aux = *s;
        *s = *p;
        *p = aux;

        ++s;
        --p;
    }
}

int strindex(char *s, char *t)
{
    char *p;
    char *q;

    while(*s != '\0')
    {
        if(*s == *t)
        {
            p = s;
            q = t;

            while(*p++ == *q++)
            {
                if(*q == '\0')
                {
                    return 0;
                }
            }
        }

        ++s;
    }

    return -1;
}

int getop(char *s)
{
    while((*s = getch()) == ' ' || *s == '\t')
        ;

    *(s + 1) = '\0';

    if(!isdigit(*s) && *s != '.')
    {
        return *s;
    }

    if(isdigit(*s))
    {
        while(isdigit(*(++s) = getch()))
            ;
    }

    if(*s == '.')
    {
        while(isdigit(*(++s) = getch()))
            ;
    }

    if(*s != EOF)
    {
        ungetch(*s);
    }

    *s = '\0';

    return 0;
}

int bufp = 0;
int buf[100];

int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c)
{
    if(bufp < 100)
    {
        buf[bufp++] = c;
    }
    else
    {
        printf("Buffer full!");
    }
}

