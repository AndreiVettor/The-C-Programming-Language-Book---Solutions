#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000
#define MAXTABS 100
#define DEFAULTTABSIZE 8

void detab(char* input, char* output, int tabc, int tablen[])
{
    int i = 0, j = 0;
    int tabcount = 1;

    // Define first tabstop
    int tabstop = tablen[tabcount];

    while(input[i] != '\n')
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

        // Check if there is a tab character
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

        ++i;
        ++j;
    }

    output[j++] = '\n';
    output[j] = '\0';
}

int getline(char* s, int maxlen)
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

void convargs(int argc, char* argv[], int* tablens)
{
    int i;
    
    for(i = 1; i < argc && i < MAXTABS; ++i) 
    {
        tablens[i] = atoi(argv[i]);
    }
}

int main(int argc, char* argv[])
{
    char input[MAXLEN];

    getline(input, MAXLEN);

    int tablens[MAXTABS];
    convargs(argc, argv, tablens);
    
    // Make a new string that has enough space to accomodate new characters
    char output[MAXLEN];
    detab(input, output, argc, tablens);

    printf("%s", output);

    return 0;
}