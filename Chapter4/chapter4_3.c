#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define NUMBER '0'
#define FUNCTION '1'
#define VARIABLE '2'

#define MAXVAR 26
#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100
#define DEBUGGING 1

int cv = 0;
double mem[MAXVAR];

double val[MAXVAL];
int sp = 0;

int buf[BUFSIZE];
int bufp = 0;
int buffer = 0;
int pushedback = 0;

int getop(char[]);
int getch(void);
void ungets(char[]);
void ungetch(int);

void printmem(void);
void show(void);
void clear(void);
void swap(void);
void peek(void);
void push(double);
double pop(void);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        if (DEBUGGING)
        {
        }

        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;

        case VARIABLE:
            if (s[0] >= 'a' && s[0] <= 'z')
            {
                cv = s[0] - 'a' + 1;
            }
            push(mem[cv]);
            break;

        case FUNCTION:
            if (!strcmp(s, "sin"))
            {
                push(sin(pop()));
            }
            else if (!strcmp(s, "pow"))
            {
                op2 = pop();
                push(pow(pop(), op2));
            }
            else if (!strcmp(s, "exp"))
            {
                push(exp(pop()));
            }
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

        case '=':
            pop(); // Remove variable value

            mem[cv] = pop();
            push(mem[cv]);
            break;

        case '\n':
            mem[0] = pop();
            push(mem[0]);
            printf("\t%.8g\n", mem[0]);
            printmem();
            break;

        default:
            printf("Error: Unkown command %s\n", s);
            break;
        }
    }

    return 0;
}

void printmem(void)
{
    printf("Variables:\n");
    printf("# = %g\n", mem[0]);
    for (int i = 0; i < MAXVAR; ++i)
    {
        printf("%c = %g\n", i + 'a', mem[i + 1]);
    }
}

void show(void)
{
    printf("Stack values:\n");
    for (int i = 0; i < sp; ++i)
    {
        printf("%g\n", val[i]);
    }
}

void clear(void)
{
    sp = 0;
}

void swap(void)
{
    if (sp > 1)
    {
        int temp = val[sp - 2];
        val[sp - 2] = val[sp - 1];
        val[sp - 1] = temp;
    }
}

void duplicate(void)
{
    if (sp > 0)
    {
        val[sp] = val[sp - 1];
        ++sp;
    }
}

void peek(void)
{
    if (sp > 0)
        printf("Top stack element: %g\n", val[sp - 1]);
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
    int i = 0, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
        if (DEBUGGING)
            printf("getop: Skipped space\n");
    }

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
    {
        if (DEBUGGING)
            printf("getop: Found noncharacter %c.\n", c);

        if (isalpha(c))
        {
            while (isalpha(s[++i] = c = getch()))
                ;
            s[i] = '\0';

            if (c == '\n')
            {
                ungetch(c);
            }

            if (strlen(s) == 1)
            {
                return VARIABLE;
            }
            else
            {
                return FUNCTION;
            }
        }

        char temp = ' ';
        if (c == '-' && isdigit(temp = getch()))
        {
            s[++i] = c = temp;
        }
        else
        {
            if (temp != ' ')
                ungetch(temp);
            return c;
        }
    }

    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    s[i] = '\0';

    if (DEBUGGING)
        printf("getop: Found number %s.\n", s);

    if (c != EOF)
    {
        ungetch(c);
    }

    return NUMBER;
}

void ungets(char s[])
{
    if (bufp + strlen(s) > BUFSIZE)
    {
        printf("Error: Buffer full\n");
    }
    else
    {
        int i = 0;
        while (s[i] != '\0')
        {
            buf[bufp++] = s[i++];
        }
    }
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

int getch1(void)
{
    if(pushedback)
    {
        pushedback = 0;
        return buffer;
    }
    return getchar();
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

void ungetch1(int c)
{
    if(!pushedback)
    {
        buffer = c;
        pushedback = 1;
    }
}