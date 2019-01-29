#include <stdio.h>

#define STRLEN 100

void escape(char s[], char t[]);

int main(void)
{
    char s[STRLEN];
    char t[STRLEN] = "Salut nene\nCe mai faci?\n\tEsti bine?";

    escape(s, t);

    printf("%s\n", s);

    return 0;
}

void escape(char s[], char t[])
{
    unsigned int i = 0;
    unsigned int j = 0;

    while(t[i] != '\0')
    {
        switch(t[i])
        {
            case '\n':
                s[j] = '\\';
                s[++j] = 'n';
                break;
            case '\t':
                s[j] = '\\';
                s[++j] = 't';
                break;
            default:
                s[j] = t[i];
                break;
        }
        ++i;
        ++j;
    }
    s[j] = '\0';
}