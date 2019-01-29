#include <stdio.h>
#define MAXLINE 1000

int getlinex(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char to[], char from[]);

main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    int emptyStrings = 0;

    max = 0;
    while (emptyStrings < 3) {
        len = getlinex(line, MAXLINE);
        if(len > 0) {
            // reverse(longest, line);
            copy(longest, line);
            printf("%s", longest);
        }
        else {
            ++emptyStrings;
        }
    }

    getchar();
    return 0;
}

int getlinex(char s[], int lim) {
    int c, lastC, i;
    
    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if(i < lim - 1 && !(lastC == c == ' '))
            s[i] = c;
        else if(lastC == c == ' ') {
            --i;
        }
        lastC = c;
    }

    if(c == '\n' && i!=0) {
        s[i] = c;
        ++i;
    }
    else {
        return 0;
    }

    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
            ++i;
    }
}

void reverse(char to[], char from[]) {
    int i, length;

    i = 0;
    length = 0;
    while(from[i] != '\0') {
        ++length;
        ++i;
    }

    for(i = 0; i < length; ++i) {
        to[i] = from[length-i-1];
    }
    to[length] = '\0';
}