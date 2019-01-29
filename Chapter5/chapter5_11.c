#include <stdio.h>
#include <string.h>

#define TAB_LENGTH 8

void entab(char str[], unsigned int size, int tabs[]);
void detab(char line[], int size, int tabs[]);
void insertSpaces(char string[], int index, int amount, int size);
int getNextTabPosition(int index, int tablen);
int count_spaces(char str[], int tabs_index, int tabs[]);

int main(int argc, char **argv)
{
    char s[] = "Hello\tthere kind sir\thow are you doing?";
    printf("input: %s\n", s);
    int tabs[] = {8, 8, 8, 8, 8, 8};

    detab(s, strlen(s), tabs);

    printf("detab: %s\n", s);

    return 0;
}

#define MAX_LENGTH 1000

void entab(char str[], unsigned int size, int tabs[])
{
    char result[MAX_LENGTH];
    unsigned int i, j;
    unsigned int result_size = 0;
    unsigned int num_copy, spaces;

    for(i = 0; i < size; i += tabs[i])
    {
        // Check how many characters to copy
        spaces = count_spaces(str, i, tabs);
        num_copy = tabs[i] - spaces;

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

    strcpy(str, result);
}

int count_spaces(char str[], int tabs_index, int tabs[])
{
    int i;
    int spaces = 0;

    for(i = tabs_index + tabs[i] - 1; i >= tabs_index; --i)
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

void detab(char line[], int size, int tabs[])
{
    int i = 0;
    while(line[i] != '\0') {
        if(line[i] == '\t') {
            insertSpaces(line, i, getNextTabPosition(i, tabs[i]), size);
        }
        ++i;
    }
}

void insertSpaces(char string[], int index, int amount, int size) 
{
    int i;

    // Shift all the characters to the left by amount units
    for(i = size + 2; i > index; --i) {
        string[i + amount - 1] = string[i];
    }

    // Put space characters in the new locations
    for(i = index; i < index + amount; ++i) {
        string[i] = ' ';
    }
}

int getNextTabPosition(int index, int tablen)
{
    return tablen - (index % tablen);
}

int getTabLength(int index, int tabs[])
{
    while(index)
    {
        
    }
}