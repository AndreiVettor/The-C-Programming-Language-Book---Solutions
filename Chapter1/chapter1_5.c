#include <stdio.h>

void main() {

    char c;

    printf("%d\n", EOF);

    c = getchar();
    while(c != EOF) {
        //printf("%d", c != EOF);
        //putchar(' ');
        putchar(c);
        c = getchar();
    }
}