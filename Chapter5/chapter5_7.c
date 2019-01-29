#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

int readlines(char *lineptr[], int nlines);
int readlines2(char storage[][MAXLEN], int maxlines);
void writelines(char *lineptr[], int nlines);
void writelines2(char lineptr[][MAXLEN], int nlines);

char *lineptr[MAXLINES];
char linearray[MAXLINES][MAXLEN];

int main(void)
{
    int nlines;

    if((nlines = readlines2(linearray, MAXLINES)) > 0)
    {
        writelines2(linearray, nlines);
        return 0;
    }
    // if ((nlines = readlines(lineptr, MAXLINES)))
    // {
    //     writelines(lineptr, nlines);
    //     return 0;
    // }
    else
    {
        printf("Number of lines too big to process!\n");
        return 1;
    }
}

int getln(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getln(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
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

int readlines2(char storage[][MAXLEN], int maxlines)
{
    int len, nlines = 0;

    while ((len = getln(storage[nlines], MAXLEN)) > 0)
    {
        printf("maxlines: %d, nlines: %d\n", maxlines, nlines);
        if (nlines >= maxlines)
        {
            return -1;
        }
        else
        {
            storage[nlines][len] = '\0';
            ++nlines;
        }
    }

    return nlines;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
    {
        return 0;
    }
}

void writelines(char *lineptr[], int nlines)
{
    while (nlines--)
    {
        printf("%s\n", *lineptr++);
    }
}

void writelines2(char lineptr[][MAXLEN], int nlines)
{
    while (nlines--)
    {
        printf("%s\n", lineptr[nlines]);
    }
}

int getln(char *s, int limit)
{
    int n = 0;

    while ((*s = getchar()) != EOF && *s != '\n')
    {
        ++s;
        ++n;
    }

    *(s + 1) = '\0';

    return n;
}