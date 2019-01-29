#include <stdio.h>

int setbits(int x, unsigned int p, unsigned int n, int y);

int main(void)
{
    int x = 0b10000000;
    int y = 0b00100111;

    printf("%x\n", setbits(x, 4, 3, y));

    return 0;
}

int setbits(int x, unsigned int p, unsigned int n, int y)
{
    // Isolate the first n bits in Y by masking
    // Shift those bits to the p position
    // Make an OR mask to keep the old X bits
    return x | (y & ~(~0 << n)) << (p + 1 - n);
}