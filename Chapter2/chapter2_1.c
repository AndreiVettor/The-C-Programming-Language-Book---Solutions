#include <stdio.h>
#include <limits.h>

int main(void)
{   
    printf("Limit of %s: %d\n", "char", CHAR_MAX);
    printf("Limit of %s: %d\n", "unsigned char", UCHAR_MAX);
    printf("Limit of %s: %d\n", "int", INT_MAX);
    printf("Limit of %s: %u\n", "unsigned int", UINT_MAX);
    printf("Limit of %s: %d\n", "float", __FLT_MAX__);
    printf("Limit of %s: %u\n", "double", __DBL_MAX__);


    return 0;
}