/*
 *  Chapter 5, Exercise 12
 *  Title: detab
 *  Author: Andrei Vettor
 *  Description: Detab with tab offset and tab length arguments
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000
#define DEFAULT_TAB_OFFSET 0
#define DEFAULT_TAB_LENGTH 4

char line[MAXLEN];
char result[MAXLEN];
int n;
int tablen;
int tabofs;

int getln(char s[], int maxlen);
void convargs(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    int i, j;
    int spaces = 0;

    n = getln(line, MAXLEN);
    convargs(argc, argv);

    for(i = 0, j = 0; i < n; ++i)
    {
        if(line[i] == '\t')
        {
            for(spaces = tablen - (j + tabofs) % tablen; spaces > 0; --spaces)
            {
                result[j++] = ' ';
            }
        }
        else
        {
            result[j++] = line[i];
        }
    }

    printf("%s", result);

    return 0;
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
        s[i++] = c;
    }

    s[i] = '\0';

    return i;
}

void convargs(int argc, char* argv[])
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
                tabofs = -atoi(argv[i]);
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