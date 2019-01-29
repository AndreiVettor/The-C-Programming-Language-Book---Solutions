#include <stdio.h>

void main() {
    
    char c;
    char lastC = '0';

    c = getchar();

    while(c != EOF) {
        if(!(lastC == ' ' && c == ' ')) {
            putchar(c);
        }
        lastC = c;
        c = getchar();
    }

    getchar();
}