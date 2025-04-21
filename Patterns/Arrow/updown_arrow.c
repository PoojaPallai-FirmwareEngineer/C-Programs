#include <stdio.h>

//   *
//  ***
// *****
//  ***
//  ***
//  ***
//  ***

//  ***
//  ***
//  ***
//  ***
// *****
//  ***
//   *


void Uparrow()
{
    int i, j, n = 3;
    //Top pattern
    for(i = 1; i <= n; i++)
    {
        for(j = i; j < n; j++)
        {
            printf(" ");
        }
        for(j = 1; j <= (2 * i - 1); j++)
        {
            printf("*");
        }
        printf("\n");
    }
    //Botom pattern
    for(i = 1; i <= 4; i++)
    {
        for(j = 1; j < 2; j++)
        {
            printf(" ");
        }
        for(j = 1; j <= 3; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void Downarrow()
{
    int i, j, n = 3;
    //Botom pattern
    for(i = 1; i <= 4; i++)
    {
        for(j = 1; j < 2; j++)
        {
            printf(" ");
        }
        for(j = 1; j <= 3; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    //Top pattern
    for(i = n; i >= 1; i--)
    {
        for(j = i; j < n; j++)
        {
            printf(" ");
        }
        for(j = 1; j <= (2 * i - 1); j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    Uparrow();
    printf("\n");
    Downarrow();
    return 0;
}