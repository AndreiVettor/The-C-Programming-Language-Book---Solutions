/*
 *  Chapter 5, Exercise 12
 *  Title: Tail
 *  Author: Andrei Vettor
 * 
 *  Description: Prints the last n lines of its input
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000
#define MAXLINES 5000
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *lineptr[MAXLINES];
int n;

void convargs(int, char *[]);
int getln(char[], int);
int readlines(char *[], int);
void writelines(char *[], int);
char *alloc(int);

int main(int argc, char* argv[])
{
    convargs(argc, argv);

    readlines(lineptr, MAXLINES);
    writelines(lineptr, n);

    return 0;
}

void convargs(int argc, char *argv[])
{
    int i;

    for(i = 1; i < argc; ++i)
    {
        switch(argv[i][0])
        {
            case '-':
            {
                n = -atoi(argv[i]);
                break;
            }
            default:
            {
                break;
            }
        }
    }
}

int getln(char s[], int maxlen)
{
    char c;
    int i = 0;

    while((c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if(c == '\n')
    {
        s[i++] = '\n';
    }

    s[i] = '\0';

    return i;
}

int readlines(char *lineptr[], int maxlines) 
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getln(line, MAXLEN)) > 0)
    {
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
        {
            return -1;
        }
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while(nlines--)
    {
        printf("%s\n", *lineptr++);
    }
}

char *alloc(int n)
{
    if(allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
    {
        return 0;
    }
}