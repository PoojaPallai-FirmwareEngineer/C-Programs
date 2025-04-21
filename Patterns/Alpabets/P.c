// To print the letter P in square shape.

#include <stdio.h>
int main()
{
    int i, n;
    scanf("%d", &n);

    // 1st line
    for (i = 0; i < n; i++)
    {
        printf("*");
    }
    printf("\n");

    //2nd line
    for (i = 0; i < n; i++)
    {
        if (i == 0 || i == n-1)
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");

    //3rd line
    for (i = 0; i < n; i++)
    {
        if (i == 0 || i == n-1)
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");

    //4th line
    for (i = 0; i < n; i++)
    {
        printf("*");
    }
    printf("\n");

    //5th line
    for(i = 0; i < n/2; i++)
    {
        printf("*\n");
    }
    printf("\n");

    return 0;
}