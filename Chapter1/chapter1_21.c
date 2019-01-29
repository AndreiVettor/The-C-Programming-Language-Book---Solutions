#include <stdio.h>

#define MAX_LENGTH 1000
#define TAB_LENGTH 8

unsigned getln(char str[], unsigned int limit);
void entab(char str[], unsigned int size);
void copy(char dest[], char src[]);

void main(void)
{
    char line[MAX_LENGTH];

    unsigned int size = getln(line, MAX_LENGTH);

    entab(line, size);

    printf("%s", line);
}

unsigned int count_spaces(char str[], unsigned int tabs_index)
{
    unsigned int i;
    unsigned int spaces = 0;

    for(i = tabs_index + TAB_LENGTH - 1; i >= tabs_index; --i)
    {
        if(str[i] == ' ')
        {
            ++spaces;
        }
        else
        {
            break;
        }
    }

    return spaces;
}

void entab(char str[], unsigned int size)
{
    char result[MAX_LENGTH];
    unsigned int i, j;
    unsigned int result_size = 0;
    unsigned int num_copy, spaces;

    for(i = 0; i < size; i += TAB_LENGTH)
    {
        // Check how many characters to copy
        spaces = count_spaces(str, i);
        num_copy = TAB_LENGTH - spaces;

        // If at the end of the string update num_copy
        if(i + num_copy > size) {
            num_copy = size - i - spaces;
        }

        // Copy the characters (forget the spaces)
        for(j = result_size; j < result_size + num_copy; ++j)
        {
            result[j] = str[i + j - result_size];
        }

        // If there were any spaces replace them with a TAB
        if(spaces)
        {
            printf("I: %d\n", i);
            result[j] = '@';
            ++result_size;
        }

        // Update the result string size
        result_size += num_copy;
    }

    result[result_size] = '\0';

    copy(str, result);
}

void copy(char dest[], char src[])
{
    unsigned int i;

    for(i = 0; src[i] != '\0'; ++i)
    {
        dest[i] = src[i];
    }

    dest[i] = '\0';
}

unsigned int getln(char str[], unsigned int limit)
{
    unsigned char c;
    unsigned int i = 0;

    // Read the string up to newline, EOF or the character limit is reached
    while((c = getchar()) != EOF && c!= '\n' && i < limit)
    {
        str[i++] = c;
    }

    // Add the newline manually
    if(c == '\n')
    {
        str[i++] = '\n';
    }

    // Make sure the string is terminated correctly
    str[i] = '\0';

    return i;
}