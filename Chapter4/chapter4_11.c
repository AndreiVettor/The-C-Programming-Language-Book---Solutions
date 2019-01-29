#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'
#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100

double val[MAXVAL];
int sp = 0;

int buf[BUFSIZE];
int bufp = 0;

int getop(char[]);
int getch(void);
void ungetch(int);

void push(double);
double pop(void);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {

        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;

        case '+':
            push(pop() + pop());
            break;

        case '-':
            op2 = pop();
            push(pop() - op2);
            break;

        case '*':
            push(pop() * pop());
            break;

        case '/':
            op2 = pop();
            if (op2 != 0)
                push(pop() / op2);
            else
                printf("Error: Cannot divide by zero!\n");
            break;

        case '%':
            op2 = pop();
            push((int)pop() % (int)op2);
            break;

        case '\n':
            printf("\t%.8g\n", pop());
            break;

        default:
            printf("Error: Unkown command %s\n", s);
            break;
        }
    }

    return 0;
}


void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("Error: Cannot push %g, stack full!\n", f);
    }
}

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("Error: Stack empty\n");
        return 0.0;
    }
}

int getop(char s[])
{
    static int buf = EOF;
    int i = 0, c;

    while ((s[0] = c = (buf == EOF) ? getch() : buf) == ' ' || c == '\t')
        buf = EOF;

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
    {

        char temp = ' ';
        if (c == '-' && isdigit(temp = getch()))
        {
            s[++i] = c = temp;
        }
        else
        {
            if (temp != ' ')
            {
                buf = temp;
            }
            return c;
        }
    }

    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = (buf == EOF) ? getch() : buf))
            buf = EOF;
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = (buf == EOF) ? getch() : buf))
            buf = EOF;
    }

    s[i] = '\0';


    if(c != EOF)
    {
        buf = c;
    }

    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp > BUFSIZE)
    {
        printf("Error: Buffer full\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
