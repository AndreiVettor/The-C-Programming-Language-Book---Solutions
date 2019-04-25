/*
 *  Chapter 5, Exercise 14
 *  Title: qsort
 *  Author: Andrei Vettor
 * 
 *  Description: Sorts lines in lexicographic or numeric order
 *      with the -n flag and in reverse with the -r flag, also
 *      fold uppercase and lowercase with -f and directory order
 *      (only letters, numbers and spaces) (-d). This version
 *      also allows field handling with (-l n) where n is the
 *      field selected (eg. -l 2)
 * 
 *  I know this solution is rather messy but I didn't want to
 *      rearchitect the whole program because of extensions. I
 *      wish the book would emphasize the need to think ahead.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 1000
#define MAXLINES 5000
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *lineptr[MAXLINES];
int numeric;
int reverse;
int folding;
int directory;
int fields;
int nlines;

void convargs(int argc, char* argv[]);
void getfield(char* s, int left, int right);

int readlines(char *v[], int nlines);
void writelines(char *lineptr[], int nlines);
char *alloc(int n);
int getln(char s[], int maxlen);

void quicksort(void *lineptr[], int left, int right,
    int (*comp)(void *, void *));
void swap(void *v[], int i, int j);
int strcmpfl(char *s1, char *s2);
int fldcmp(char* s1, char* s2);
char* skipnonchar(char *s);
int numcmp(char *, char *);


int main(int argc, char* argv[])
{
    convargs(argc, argv);

    if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        void* sorter;

        if(numeric)
        {
            sorter = (int (*)(void*, void*))numcmp;
        }
        else if(fields)
        {
            sorter = (int (*)(void*, void*))fldcmp;
        }
        else if(folding || directory)
        {
            sorter = (int (*)(void*, void*))strcmpfl;
        }
        else
        {
            sorter = strcmp;
        }
        
        quicksort((void**) lineptr, 0, nlines - 1, sorter);
        
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("Input too big to sort\n");
        return 1;
    }

    return 0;
}

int fldcmp(char* s1, char* s2)
{
    int count;
    char* pch;

    for(count = 1; count < fields; ++count)
    {
        if(!(pch = strchr(s1, '\t')))
        {
            return -1;
        }
        else
        {
            s1 = ++pch;
        }
    }
    for(count = 1; count < fields; ++count)
    {
        if(!(pch = strchr(s2, '\t')))
        {
            return 1;
        }
        else
        {
            s2 = ++pch;
        }
    }

    if(folding || directory)
    {
        return strcmpfl(s1, s2);
    }
    else
    {
        return strcmp(s1, s2);
    }
    
}

void quicksort(void *v[], int left, int right,
    int (*comp)(void*, void*))
{
    int i, last;

    if(left >= right)
    {
        return;
    }
        
    swap(v, left, (left + right) / 2);

    last = left;
    for(i = left + 1; i <= right; ++i)
    {
        if(reverse == 1 ? (*comp)(v[i], v[left]) > 0
            : (*comp)(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    quicksort(v, left, last - 1, comp);
    quicksort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if(v1 < v2)
    {
        return -1;
    }
    else if(v1 > v2)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int strcmpfl(char *s1, char *s2)
{
    if(directory)
    {
        s1 = skipnonchar(s1);
        s2 = skipnonchar(s2);
    }

    while(folding ? (tolower(*s1) == tolower(*s2)) : (*s1 == *s2))
    {
        ++s1;

        if(*s1 == '\0' || (fields && *s1 == '\t'))
        {
            return 0;
        }

        ++s2;

        if(directory)
        {
            s1 = skipnonchar(s1);
            s2 = skipnonchar(s2);
        }
    }

    return folding ? (tolower(*s1) - tolower(*s2)) : (*s1 - *s2);
}

char* skipnonchar(char *s)
{
    while(!isalnum(*s) && !isspace(*s))
    {
        if(fields && (*s == '\t' || *s == '\0'))
        {
            break;
        }
        s++;
    }

    return s;
}

void convargs(int argc, char* argv[]) 
{
    char *pch;
    int i;

    numeric = 0;
    reverse = 0;
    fields = 0;

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
                    if(folding)
                    {
                        folding = 0;
                        printf("Ignoring folding (-f) because of numeric ordering (-n)\n");
                    }
                    if(directory)
                    {
                        directory = 0;
                        printf("Ignoring directory mode (-d) because of numeric ordering (-n)\n");
                    }
                    numeric = 1;
                    printf("Ordering in numeric order. (-n)\n");
                }
                if(strchr(argv[i], 'r') != NULL)
                {
                    printf("Ordering in reverse. (-r)\n");
                    reverse = 1;
                }
                if(strchr(argv[i], 'f') != NULL)
                {
                    if(numeric == 1)
                    {
                        printf("Ignoring folding (-f) because of numeric ordering (-n)\n");
                    }
                    else
                    {
                        printf("Folding uppercase and lowercase (-f)\n");
                        folding = 1;
                    }
                }
                if(strchr(argv[i], 'd') != NULL)
                {
                    if(numeric == 1)
                    {
                        printf("Ignoring directory order (-d) because of numeric ordering (-n)\n");
                    }
                    else
                    {
                        printf("Directory order enabled (-d)\n");
                        directory = 1;
                    }
                }
                if((pch = strchr(argv[i], 'l')) != NULL)
                {
                    if(fields = atoi(pch + 2))
                    {
                        // Only move to the next argument if the field has been specified
                        ++i;
                        printf("Sorting on field %d\n", fields);
                    }
                    else
                    {
                        printf("Field index invalid, ignoring flag (-l)\n");
                    }
                    
                }
            }
        }
    }
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getln(line, MAXLEN)) > 0)
    {
        if(nlines > maxlines || (p = alloc(len)) == NULL)
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
    while (nlines--)
    {
        printf("%s\n", *lineptr++);
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