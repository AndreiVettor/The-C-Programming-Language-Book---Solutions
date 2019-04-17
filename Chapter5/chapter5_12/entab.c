/*
 *  Chapter 5, Exercise 12
 *  Title: Entab
 *  Author: Andrei Vettor
*/

#include <stdio.h>
#include <math.h>


#define MAXLEN 1000
#define DEFAULT_TAB_OFFSET 0
#define DEFAULT_TAB_LENGTH 8


int get_line(char*, int);
void initialize(int, char**);
void entab();


char input[MAXLEN];
int n;
int tabofs;
int tablen;


int main(int argc, char* argv[])
{
    initialize(argc, argv);
    n = get_line(input, MAXLEN);

    entab();

    printf("%s", input);

    return 0;
}

int get_line(char s[], int maxlines)
{
    char c;
    int i = 0;

    while((c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }

    if(c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';

    return i;
}

void initialize(int argc, char* argv[])
{
    int i;

    tabofs = DEFAULT_TAB_OFFSET;
    tablen = DEFAULT_TAB_LENGTH;

    for(i = 1; i < argc; ++i)
    {
        switch(argv[i][0])
        {
            case '-':
            {
                tabofs = abs(atoi(argv[i]));
                break;
            }
            case '+':
            {
                tablen = atoi(argv[i]);
                break;
            }
            default:
            {
                break;
            }
        }
    }
}

void entab() 
{
    int i;
    int result[MAXLEN];

    for(i = tablen + tabofs; i < n - tablen; i += tablen)
    {
        if(i != ' ')
        {
            
        }
    }
}

// This is one of the tests
//        ^

// Makelhausendorf hah
//        ^