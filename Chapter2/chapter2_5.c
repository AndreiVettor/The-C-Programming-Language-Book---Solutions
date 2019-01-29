#include <stdio.h>
#include <string.h>

unsigned int any(char s1[], char s2[]);

int main(void)
{
    char s1[] = "Salut domnule!";
    char s2[] = "#";

    printf("First String: %s\n", s1);
    printf("Second String: %s\n", s2);
    printf("First occurence: %d\n", any(s1, s2));

    return 0;
}

unsigned int any(char s1[], char s2[])
{
    unsigned int i, j;

    for(i = 0; i < strlen(s1); ++i)
    {
        for(j = 0; j < strlen(s2); ++j)
        {
            if(s1[i] == s2[j])
            {
                return i;
            }
        }
    }
    return -1;
}