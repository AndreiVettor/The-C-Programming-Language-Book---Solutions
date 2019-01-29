#include <stdio.h>

#define MAX_LENGTH 1000
#define WRAP_SIZE 20

unsigned int getln(char str[], unsigned int limit);
unsigned int insertCharacter(char str[], unsigned int size, unsigned int index, char character);
int getFirstBlank(char str[], unsigned int column, unsigned int lineLengh);
void wrapLine(char str[], unsigned int size, unsigned int lineLength);

void main(void)
{
    char line[MAX_LENGTH];

    unsigned int size = getln(line, MAX_LENGTH);

    wrapLine(line, size, WRAP_SIZE);

    printf("%s", "12345678901234567890\n");
    printf("%s", line);
}

void wrapLine(char str[], unsigned int size, unsigned int lineLength)
{   
    unsigned int i;
    int blankIndex = 0;
    int previousIndex = 0;

    for(i = lineLength; i < size; )
    {
        blankIndex = getFirstBlank(str, i, lineLength);

        if(blankIndex == 0 && str[i] != ' ')
        {
            // str[previousIndex] = ' ';

            insertCharacter(str, size, i, '-');
            insertCharacter(str, size, i+1, '\n');
            size += 2;
            i += lineLength;
        }
        else
        {
            str[blankIndex] = '\n';
            i = blankIndex + lineLength;
        }

        previousIndex = blankIndex;
    }
}

unsigned int insertCharacter(char str[], unsigned int size, unsigned int index, char character)
{
    unsigned int i;

    // Shift all the characters following the desired index
    for(i = size; i > index; --i)
    {
        str[i] = str[i - 1];
    }

    // Insert character
    str[index] = character;

    // Fix new size null termination
    str[size + 1] = '\0';
}

int getFirstBlank(char str[], unsigned int column, unsigned int lineLengh)
{   
    unsigned int i;

    for(i = column; i > column - lineLengh; --i)
    {
        if(str[i] == ' '  || str[i] == '\t')
        {
            return i;
        }
    }

    return 0;
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