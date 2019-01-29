#include <stdio.h>

/**
 * Prints a histogram of length of words
 * 
 **/

#define MAXLENGTH 12

void main() {
    char c;
    int lengths[MAXLENGTH];
    int currentLength = 0;
    c = getchar();

    for(int i = 0; i < MAXLENGTH; i++) {
        lengths[i] = 0;
    }

    // Read characters until q is found
    while(c != EOF) {
        if(c == ' ' || c == '\t' || c == '\n') {
            if(currentLength >= MAXLENGTH) {
                ++lengths[0];
            }
            else {
                ++lengths[currentLength];
            }
            currentLength = 0;
        }
        else {
            ++currentLength;
        }
        c = getchar();
    }

    // Print horizontal histogram
    for(int i = 1; i < MAXLENGTH; i++) {
        printf("%s%d%s", "Length ", i, ":\t");
        
        for(int j = 0; j < lengths[i]; j++) {
            putchar('=');
        }

        putchar('\n');
    }

    printf("Length 12+:\t");
    for(int j = 0; j < lengths[0]; j++) {
            putchar('=');
        }

    putchar('\n');

    // Print vertical histogram
    for(int j = 10; j > 0; j--) {
        for(int i = 1; i < MAXLENGTH; i++) {
            if(lengths[i] >= j)
                printf("  #");
            else {
                printf("   ");
            }
        }
        if(lengths[0] >= j) {
            printf("  #");
        }
        else {
            printf("   ");
        }
        putchar('\n');
    }

    putchar('\n');

    for(int i = 1; i < MAXLENGTH; i++) {
        printf("%3d", i);
    }
    printf("%3d+", MAXLENGTH);

    getchar();
}