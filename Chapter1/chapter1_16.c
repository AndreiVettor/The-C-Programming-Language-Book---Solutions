#include <stdio.h>
#define MAXLINE 10

int getlinex(char line[], int maxline);
void copy(char to[], char from[]);

main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getlinex(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
            if(len >= 80) {
                printf("%s", len);
            }
        }
    }
    if(max > 0) {
        printf("MAX - %d characters: %s", max, longest);
    }

    getchar();
    return 0;
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

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}