#include <stdio.h>

#define MAX_LENGTH 1000

unsigned int getln(char str[], unsigned int limit);
unsigned int insideQuotes(char str[], unsigned int index);
void deleteCharacter(char str[], unsigned int index);
void uncomment(char str[]);

void main(void)
{
    char line[MAX_LENGTH];

    getln(line, MAX_LENGTH);

    uncomment(line);

    printf("%s", line);
}

void uncomment(char str[])
{
    char c;
    unsigned int i;

    for(i = 0; str[i] != '\n'; ++i)
    {
        if(str[i] == '/' && str[i+1] == '/' && !insideQuotes(str, i))
        {
            deleteCharacter(str, i);
            deleteCharacter(str, i);
            break;
        }
    }
}

void deleteCharacter(char str[], unsigned int index)
{
    char c;
    unsigned int i = index;

    while(str[i] != '\n')
    {
        str[i] = str[i+1];
        ++i;
    }
}

unsigned int insideQuotes(char str[], unsigned int index)
{
    unsigned int singleQuotesCount = 0;
    unsigned int doubleQuotesCount = 0;
    unsigned int i;

    for(i = 0; i < index; ++i)
    {
        if(str[i] == '\"')
        {
            ++doubleQuotesCount;
        }
        else if(str[i] == '\'')
        {
            ++singleQuotesCount;
        }
    }

    if(doubleQuotesCount % 2 == 1 || singleQuotesCount % 2 == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

unsigned int getln(char str[], unsigned int limit)
{
    char c;
    unsigned int i = 0;

    while((c = getchar()) != EOF && c != '\n' && i < limit)
    {
        str[i++] = c;
    }

    if(c == '\n')
    {
        str[i++] = '\n';
    }

    str[i] = '\0';

    return i;
}