#include <stdio.h>

void main() {

    int spaces = 0;
    int tabs = 0;
    int newlines = 0;
    char c;
    
    c = getchar();
    while(c != EOF) {
        if(c == ' ') {
            ++spaces;
        }
        else if(c == '\t') {
            ++tabs;
        }
        else if(c == '\n') {
            ++newlines;
        }
        else if(c == 'q') {
            break;
        }
        c = getchar();
    }
    printf("Spaces: %d\nTabs: %d\nNewlines: %d", spaces, tabs, newlines);
}