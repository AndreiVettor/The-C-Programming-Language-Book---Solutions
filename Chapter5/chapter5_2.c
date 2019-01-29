#include <stdio.h>
#include <ctype.h>

#define MAXOP 100

int bufp = 0;
int buf[MAXOP];

int getch(void);
void ungetch(int);
int getfloat(float *);
void printbuf(void);

int main(void)
{
    float x;

    getfloat(&x);

    printf("%f\n", x);
    // printbuf();

    return 0;
}

int getfloat(float *pn)
{
    int c, sign;
    int power = 1;

    *pn = 0;

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
    if(c == '.')
    {
        c = getch();
    }
    for (; isdigit(c); c = getch())
    {
        *pn = 10 * (*pn) + (c - '0');
        power *= 10;
    }

    (*pn) = sign * (*pn / power);

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