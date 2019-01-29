#include <stdio.h>

void main() {
    
    char c;
    c = getchar();

    while(c != EOF) {
        if(c == ' ' || c == '\t') {
            putchar('\n');
        }
        else {
            putchar(c);
        }
        c = getchar();
    }
}