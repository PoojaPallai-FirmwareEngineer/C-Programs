//Double arrow using for loop.
/*
  *               *
 *******************
*********************
 *******************
  *               *

   1st -17
   2nd -18
   3rd -19
   4th -18
   5th -17
*/

#include <stdio.h>
int main()
{
    int n = 19, i;

    //1st line
    for(i = 0; i < 2; i++)
    {
        printf(" ");
    }
    printf("*");
    for(i = 0; i < 15; i++)
    {
        printf(" ");
    }
    printf("*\n");

    //2 line
    for(i = 0; i < 1; i++)
    {
        printf(" ");
    }
    printf("*");
    for(i = 0; i < 18 ; i++)
    {
        printf("*");
    }
    printf("\n");

    //3rd line
    for(i = 0; i < 21 ; i++)
    {
        printf("*");
    }
    printf("\n");

    //4th line
    for(i = 0; i < 1; i++)
    {
        printf(" ");
    }
    printf("*");
    for(i = 0; i < 18 ; i++)
    {
        printf("*");
    }
    printf("\n");

    //5th line
    for(i = 0; i < 2; i++)
    {
        printf(" ");
    }
    printf("*");
    for(i = 0; i < 15; i++)
    {
        printf(" ");
    }
    printf("*\n");
}

