// To print O in square pattern

#include <stdio.h>
int main()
{
    int i, j, n;
    scanf("%d", &n);

    // 1st line
    for (i = 0; i < n; i++)
    {
        printf("*");
    }
    printf("\n");

    //2nd line
    for (i = 0; i < n-2; i++)
    {
        printf("*");
        for(j = 0; j < n-2; j++)
        {
            printf(" ");
        }
        printf("*\n");
    }

        
    //3th line
    if(n > 1)
    {
        for (i = 0; i < n; i++)
        {
            printf("*");
        }
        printf("\n");
    }

    
}