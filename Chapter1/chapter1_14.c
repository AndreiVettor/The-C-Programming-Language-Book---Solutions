#include <stdio.h>

/* Prints a histogram of the frequencies of
 *  different characters
 */

void main() {
    char c;
    int frequencies[10];

    for(int i = 0; i < 10; i++) {
        frequencies[i] = 0;
    }

    c = getchar();
    while(c != 'q') {
        if(c >= '0' && c <= '9') {
            ++frequencies[c - '0'];
        }
        c = getchar();
    }

    for(int i = 0; i < 10; i++) {
        printf("%s%d%s", "Length ", i, ":\t");
        
        for(int j = 0; j < frequencies[i]; j++) {
            putchar('=');
        }

        putchar('\n');
    }
}