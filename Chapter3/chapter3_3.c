#include <stdio.h>
#include <ctype.h>

#define VLEN 1000

void expand(char s1[], char s2[]);
unsigned int expandrange(char str[], unsigned int index, char lowerlim, char upperlim);

int main(void)
{
    char s1[VLEN] = "-1-3a-z0-2-6";
    char s2[VLEN];
    
    expand(s1, s2);

    printf("%s\n", s2);

    return 0;
}

void expand(char s1[], char s2[])
{
    unsigned int i = 0;
    unsigned int strsize = 0;
    char lowerlim;
    char upperlim;

    if(s1[i] == '-')
    {
        // Do something with leading dash
        ++i;
    }

    // Get the first lower limit
    lowerlim = s1[i++];

    while(1)
    {
        if(s1[i] == '\0')
        {
            return;
        }

        if(s1[i] == '-')
        {
            if(s1[i+1] == '\0')
            {
                // Do something with trailing dash
                return;
            }

            upperlim = s1[++i]; // If not a dash, get next upperlim
            strsize = expandrange(s2, strsize, lowerlim, upperlim);
            printf("%d\n", strsize);
            lowerlim = upperlim; // Update lowerlim
        }
        else if(isalnum(s1[i]))
        {
            lowerlim = s1[i];
        }
        else 
        {
            printf("Invalid range format\n");
            s2 = "";
            return;
        }
        ++i;
    }
}

unsigned int expandrange(char str[], unsigned int index, char lowerlim, char upperlim)
{
    int count = 0;
    unsigned int i;

    for(i = index; i < index + upperlim + 1 - lowerlim; ++i)
    {
        str[i] = lowerlim + (count++);
    }

    str[i] = '\0';

    return i;
}