#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

float expr(int n, char *input[]);
void push(float val);
float pop();

int main(int argc, char *argv[])
{
    if(argc > 1)
        printf("Result: %f\n", expr(argc, argv));
    else
        printf("Usage: 2 4 +\n");

    return 0;
}

#define NUMBER 1

float expr(int n, char *input[])
{
    int type, op;
    int c;

    while(--n)
    {
        *(++input);

        if(!isdigit(c = **input) && strlen(*input) == 1)
            type = c;
        else
            type = NUMBER;

        switch(type)
        {
            case '\0':
                printf("Empty input!\n");
                break;
            case NUMBER:
                push(atof(*input));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op = pop();
                push(pop() - op);
                break;
            case '/':
                op = pop();
                if(op != 0)
                    push(pop() / op);
                break;
            case 'x':
                push(pop() * pop());
                break;
            default:
                printf("Invalid input! %d(%c)\n", type, type);
                break;
        }
    }

    return pop();
}

#define STACKSIZE 1000

static float stack[STACKSIZE];
static int stackp = 0;

void push(float val)
{
    if(stackp < STACKSIZE)
    {
        stack[stackp++] = val;
    }
    else
    {
        printf("Stack is full!\n");
    }
}

float pop()
{
    if(stackp > 0)
    {
        return stack[--stackp];
    }
    else
    {
        printf("Stack is empty!\n");
    }
}

// Observations
// On the machine this program was developed the shell was globbing the "*"
// character so I had to replace it with "x"