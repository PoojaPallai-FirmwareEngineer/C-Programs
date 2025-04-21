/*
***********
 *********
  *******
   *****
    ***
     *
    ***
   *****
  *******
 *********
***********
*/

#include <stdio.h>
int main()
{
    int i, j, n =6;
    //Bottom pattern
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
}