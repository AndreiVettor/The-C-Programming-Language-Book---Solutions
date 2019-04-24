#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000
#define MAXTABS 100
#define DEFAULTTABSIZE 8

void detab(char input[], int tabc, int tablen[])
{
    char output[MAXLEN];

    int i, j;
    int tabcount = 1;

    // Define first tabstop
    int tabstop = tablen[tabcount];

    for(i = 0, j = 0; input[i] != '\0'; ++i, ++j)
    {
        // Track current tabstop
        if(j >= tabstop)
        {
            if(tabcount >= tabc)
            {
                tabstop += DEFAULTTABSIZE;
            }
            else
            {
                tabstop += tablen[tabcount++];
            }
        }

        //  if there's a tab character fill the rest of characters with spaces
        if(input[i] == '\t')
        {
            int spaces;
            for(spaces = tabstop - j; spaces > 0; --spaces, ++j)
            {
                output[j] = ' ';
            }
            --j;
        }
        else
        {
            output[j] = input[i];
        }
    }

    output[j] = '\0';

    strcpy(input, output);
}

void entab(char input[], int tabc, int tablen[])
{
    int i, j = 0;
    int tabcount = 1;
    int spaces = 0;

    char result[MAXLEN];

    for(i = 0; input[i] != '\0'; ++i, ++j)
    {
        if(i == tablen[tabcount])
        {
            if(tabcount >= tabc)
            {
                tablen[tabcount] = DEFAULTTABSIZE;
            }
            else
            {
                ++tabcount;
            }

            if(spaces > 0)
            {
                result[j++] = '\t';
                spaces = 0;
            }
        }

        if(input[i] == ' ')
        {
            ++spaces;
        }
        else
        {
            result[j] = input[i];
            spaces = 0;
        }
    }

    result[++j] = '\0';

    strcpy(result, input);
}

int get_line(char s[], int maxlen)
{
    int c, i = 0;

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

void convargs(int argc, char* argv[], int tablens[])
{
    int i;
    
    // Convert unused position to a 0-index reference
    tablens[0] = 0;

    for(i = 1; i < argc && i < MAXTABS; ++i) 
    {
        tablens[i] = atoi(argv[i]);
    }
}

int main(int argc, char* argv[])
{
    char text[MAXLEN];

    get_line(text, MAXLEN);

    int tablens[MAXTABS];
    convargs(argc, argv, tablens);

    detab(text, argc, tablens);
    printf("%s", text);

    entab(text, argc, tablens);
    printf("%s", text);

    return 0;
}