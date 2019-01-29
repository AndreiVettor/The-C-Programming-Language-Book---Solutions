#include <stdio.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    char s[100];

    itob(125, s, 16);

    printf("%s\n", s);

    return 0;
}

void itob(int n, char s[], int b)
{
    unsigned int i = 0;

    while(n > 0)
    {
        if(n % b <= 9) 
        {
            s[i++] = (n % b) + '0';
        }
        else if(n % b > 9)
        {
            s[i++] = (n % b) - 10 + 'A';
        }
        n /= b;
    }
    
    s[i] = '\0';

    reverse(s);
}

void reverse(char s[])
{
    unsigned int i, j = 0, n = 0;
    char c;

    while(s[j++] != '\0');
    j -= 2;
    n = j+1;

    for(i = 0; i < n/2, j > n/2; ++i, --j)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}