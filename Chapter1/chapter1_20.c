#include <stdio.h>

#define MAX_LENGTH 1000
#define TAB_LENGTH 4

char line[MAX_LENGTH];
unsigned size;

void detab(char[], unsigned);
void insertSpaces(char[], unsigned, unsigned, unsigned);
int getlinex(char[], int);
unsigned getNextTabPosition(unsigned);

void main() {
    // char test[] = "Salut ba\tCe faci? Mai\tfumezi?\n";
    // detab(test, 31);
    // printf("%s", test);
    while(size = getlinex(line, MAX_LENGTH)) {
        detab(line, size);
        printf("%s", line);
    }
}

void detab(char line[], unsigned size) {
    unsigned i = 0;
    while(line[i] != '\0') {
        if(line[i] == '\t') {
            insertSpaces(line, i, getNextTabPosition(i), size);
        }
        ++i;
    }
}

void insertSpaces(char string[], unsigned index, unsigned amount, unsigned size) {
    unsigned i;

    // Shift all the characters to the left by amount units
    for(i = size + 2; i > index; --i) {
        string[i + amount - 1] = string[i];
    }

    // Put space characters in the new locations
    for(i = index; i < index + amount; ++i) {
        string[i] = ' ';
    }
}

unsigned getNextTabPosition(unsigned index) {
    return TAB_LENGTH - (index % TAB_LENGTH);
}

int getlinex(char s[], int lim) {
    int c, i;
    
    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if(i < lim - 1)
            s[i] = c;
    }

    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}