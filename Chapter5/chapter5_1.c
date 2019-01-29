#include <stdio.h>
#include <ctype.h>

#define MAXOP 100

int bufp = 0;
int buf[MAXOP];

int getch(void);
void ungetch(int);
int getint(int *);
void printbuf(void);

int main(void)
{
    int x = 0;
    int result;

    result = getint(&x);

    printf("X: %d\n", x);
    printbuf();

    return 0;
}

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '-' && c != '+')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+')
    {
        c = getch();

        if(!isdigit(c))
        {
            ungetch(c);
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * (*pn) + (c - '0');
    }

    (*pn) *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

void printbuf(void)
{
    printf("Buffer values:\n");
    for(int i = 0; i < bufp; ++i)
    {
        printf("%c\n", buf[i]);
    }
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp > MAXOP)
    {
        printf("ungetch: Buffer full!\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}