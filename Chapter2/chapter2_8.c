#include <stdio.h>

unsigned int rightrot(unsigned int x, unsigned int n);

int main(void)
{
    unsigned int x = 0b00010100;

    printf("%x\n", rightrot(x, 3));

    return 0;
}

unsigned int rightrot(unsigned int x, unsigned int n)
{
    return (((~(~0 << n))) & x) << ((sizeof(x) << 3) - n) | (x >> n);
}