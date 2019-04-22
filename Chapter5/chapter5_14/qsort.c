/*
 *  Chapter 5, Exercise 14
 *  Title: qsort
 *  Author: Andrei Vettor
 * 
 *  Description: Sorts lines in lexicographic or numeric order
 *      with the -n flag and in reverse with the -r flag
*/

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000
#define MAXLINES 5000

char *lineptr[MAXLINES];
int numeric = 0;
int reverse = 0;

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right,
    int (*comp)(void *, void *));
int numcmp(char *, char *);
void convargs(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    int nlines;

    convargs(argc, argv);
    
    readlines(lineptr, MAXLINES);


    return 0;
}

void convargs(int argc, char* argv[]) 
{
    int i;

    if(argc > 1)
    {
        for(i = 1; i < argc; ++i)
        {
            // If dash argument
            if(argv[i][0] == '-')
            {
                // Contains -n flag
                if(strchr(argv[i], 'n') != NULL)
                {
                    numeric = 1;
                    printf("Ordering in numeric order. (-n)\n");
                }
                if(strchr(argv[i], 'r') != NULL)
                {
                    printf("Ordering in reverse. (-r)\n");
                    reverse = 1;
                }
            }
        }
    }
}

int readlines(char *lineptr[], int nlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getln(line, MAXLEN)) > 0)
    {
        if(nlines > MAXLINES || (p = alloc(len) == NULL))
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