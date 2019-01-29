#include <stdio.h>

#define MAX_LENGTH 1000
#define TRUE (1==1)
#define FALSE !TRUE

unsigned int par_open = FALSE;
unsigned int sqr_bracket_open = FALSE;
unsigned int bracket_open = FALSE;

unsigned int in_quote = 0;

void getstr(char str[], unsigned int limit);
void checksyntax(char str[]);
unsigned int checkcomment(char str[], unsigned int index);

int main(void)
{
    char input_string[MAX_LENGTH];

    getstr(input_string, MAX_LENGTH);
    checksyntax(input_string);

    return 0;
}

void checksyntax(char str[])
{
    unsigned int i = 0;

    while(str[i++] != '\0')
    {
        // Skip rest of line if commented
        i = checkcomment(str, i);

        // Keep track of paratheses and quotes
        if(!in_quote) 
        {
            if(str[i] == '{')
            {
                bracket_open = TRUE;
            }
            else if(str[i] == '[')
            {
                sqr_bracket_open = TRUE;
            }
            else if(str[i] == '(')
            {
                par_open = TRUE;
            }
            else if(str[i] == '\'' || str[i] == '\"')
            {
                in_quote = TRUE;
            }
            else if(str[i] == '}' && bracket_open)
            {
                bracket_open = FALSE;
            }
            else if(str[i] == ']' && sqr_bracket_open)
            {
                sqr_bracket_open = FALSE;
            }
            else if(str[i] == ')' && par_open)
            {
                par_open = FALSE;
            }
        }
        else
        {
            if(str[i] == '\'' || str[i] == '\"')
            {
                in_quote = FALSE;
            }
        }
    }

    if(bracket_open)
    {
        printf("Bracket missing\n");
    }
    if(sqr_bracket_open)
    {
        printf("Brace missing\n");
    }
    if(par_open)
    {
        printf("Parathesis missing\n");
    }
    if(in_quote)
    {
        printf("Quote missing\n");
    }
}

unsigned int checkcomment(char str[], unsigned int index)
{
    if(str[index] == '/' && str[index+1] == '/')
        {
            index += 2;
            while(str[index++] != '\n');
        }
        
    return index;
}

void getstr(char str[], unsigned int limit)
{
    char c;
    unsigned int i = 0;

    while((c = getchar()) != EOF && i < limit)
    {
        str[i++] = c;
    }

    str[i] = '\0';
}