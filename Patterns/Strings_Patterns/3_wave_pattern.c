// **Print the given string in a wave pattern.**
// H   O  
//  E L   
//   L  
//  E L   
// H   O

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "HELLO";
    int len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        // Print leading the spaces to form the wave pattern
        if (i <= len / 2)
        {
            for(int j = 0; j < i; j++)
            {
                printf(" ");
            }
        }
        else
        {
            for(int j = 0; j < len - i - 1; j++)
            {
                printf(" ");
            }
        }

        // Handle each row based on the wave structure
        if (i == 0 || i == len - 1)
        {
            // 1st and last row: print first and last characters with 3 spaces
            printf("%c", str[0]); // H
            for(int j = 0; j < len - 2; j++)
            {
                printf(" ");
            }
            printf("%c", str[4]); // O
        }
        else if (i == 1 || i == len - 2)
        {
            // 1st and last row: print second and fourth characters with 3 spaces
            printf("%c", str[1]); // E
            for(int j = 0; j < len - 4; j++)
            {
                printf(" ");
            }
            printf("%c", str[3]); // L
        }
        else if (i == 2)
        {
            // Middle row: print the middle character
            printf("%c", str[2]); // L
        }
        printf("\n");
    }
    return 0;
}