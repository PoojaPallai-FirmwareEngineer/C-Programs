// **Print a string in a diamond pattern.**
//   A  
//  B B  
// C   C  
//  B B  
//   A 

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "ABCD";
    int len = strlen(str) - 1;
    int i, j;

    // Top half of diamond
    for(i = 0; i < len; i++)
    {
        for(j = 0; j < len -i - 1; j++)
        {
            printf(" ");
        }
        printf("%c", str[i]);

        for(j = 0; j < 2 * i - 1; j++)
        {
            printf(" ");
        }

        if (i > 0)
        {
            printf("%c", str[i]);
        }
        printf("\n");
    }

    // Bottom half of diamond
    for(i = len - 2; i >= 0; i--)
    {
        for(j = 0; j < len -i - 1; j++)
        {
            printf(" ");
        }
        printf("%c", str[i]);

        for(j = 0; j < 2 * i - 1; j++)
        {
            printf(" ");
        }

        if (i > 0)
        {
            printf("%c", str[i]);
        }
        printf("\n");
    }

}