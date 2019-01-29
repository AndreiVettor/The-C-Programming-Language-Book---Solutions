#include <stdio.h>

int invert(int x, unsigned int p, unsigned int n);

int main(void)
{
    int x = 0b00010100;

    printf("%x\n", invert(x, 5, 4));

    return 0;
}

int invert(int x, unsigned int p, unsigned int n)
{
    return (~(~0 << n) << (p + 1 - n)) ^ x;
}