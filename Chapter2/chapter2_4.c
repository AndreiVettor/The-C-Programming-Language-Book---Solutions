#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void)
{
    char str1[] = "Salut domnule! Ce mai faci?";
    char str2[] = "aeiou";

    squeeze(str1, str2);

    printf("%s\n", str1);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    unsigned int i = 0;
    unsigned int new_index = 0;
    unsigned int j = 0;
    unsigned int ok;

    while(s1[i] != '\0')
    {
        ok = 1;
        j = 0;
        while(s2[j] != '\0')
        {
            if(s1[i] == s2[j])
            {
                ok = 0;
            }

            ++j;
        }

        if(ok)
        {
            s1[new_index++] = s1[i];
        }

        ++i;
    }
    s1[new_index] = '\0';
}