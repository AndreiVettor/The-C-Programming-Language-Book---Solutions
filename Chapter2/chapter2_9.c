#include <stdio.h>

unsigned int bitcount(unsigned int x);

int main(void)
{
    unsigned int x = 0b00111000;

    printf("%d\n", bitcount(x));

    return 0;
}

unsigned int bitcount(unsigned int x)
{
    unsigned int bits = 0;

    while((x &= (x-1)))
    {
        ++bits;
    }
    if(bits) {
        ++bits;
    }

    return bits;
}