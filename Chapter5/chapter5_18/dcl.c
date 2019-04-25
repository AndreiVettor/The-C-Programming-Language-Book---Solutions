/*
 *  Chapter 5, Exercise 14
 *  Title: dcl
 *  Author: Andrei Vettor
 * 
 *  Description: Converts a C declaration into a
 *      word description
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void undcl(void);

int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int main(void)
{
    while(gettoken() != EOF)
    {
        strcpyp(datatype, token);
        out[0] = '\0';
        dcl();

        if(tokentype != '\n')
        {
            printf("Syntax error!\n");
        }
        printf("%s: %s %s\n", name, out, datatype);
    }

    return 0;
}