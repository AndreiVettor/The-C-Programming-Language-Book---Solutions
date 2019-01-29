#include <stdio.h>

#define MAX_LENGTH 1000

void getln(char str[], unsigned int limit);

int main(void)
{
    char line[MAX_LENGTH];

    getln(line, MAX_LENGTH);

    printf("%s\n", line);

    return 0;
}

void getln(char str[], unsigned int limit)
{
    unsigned int i;
    char c;

    for (i = 0; i < (limit - 1) * ((c=getchar()) != '\n') * (c != EOF); ++i)
        str[i] = c;

    if(str[i] == '\n')
    {
        str[i++] = '\n';
    }
    str[i] = '\0';
}