#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NUMBER '0'

#define MAXLENGTH 1000
#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100
#define DEBUGGING 1

double val[MAXVAL];
int sp = 0;

char line[MAXLENGTH];

int getop(char[], char[]);
unsigned int getln(char[], unsigned int);

void push(double);
double pop(void);
void print(void);

int main()
{
    double op2;
    unsigned int i, j;
    char n[MAXLENGTH];

    while (getln(line, MAXLENGTH))
    {
        for (i = 0; line[i] != '\n'; ++i)
        {

            if(line[i] == ' ')
                continue;

            print();
                
            if (isdigit(line[i]))
            {
                j = 0;
                n[j++] = line[i];
                while (isdigit(line[i+1]))
                {
                    n[j++] = line[++i];
                }
                if(line[i+1] == '.')
                {
                    n[j++] = line[i+1];
                    ++i;
                    while (isdigit(line[i+1]))
                    {
                        n[j++] = line[++i];
                    }
                }
                n[j] = '\0';
                push(atof(n));
            }
            else
            {
                switch (line[i])
                {
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

                default:
                    printf("Error: Unkown command %s\n", line[i]);
                    break;
                }
            }

        }
        if(line[i] == '\n')
        {
            printf("\t%.8g\n", pop());
        }

    }

    return 0;
}

void print(void)
{
    printf("Stack values:\n");
    for(int i = 0; i < sp; ++i)
    {
        printf("%g\n", val[i]);
    }
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

unsigned int getln(char str[], unsigned int limit)
{
    unsigned char c;
    unsigned int i = 0;

    // Read the string up to newline, EOF or the character limit is reached
    while((c = getchar()) != EOF && c!= '\n' && i < limit)
    {
        str[i++] = c;
    }

    // Add the newline manually
    if(c == '\n')
    {
        str[i++] = '\n';
    }

    // Make sure the string is terminated correctly
    str[i] = '\0';

    return i;
}