// **Pyramid of Characters**
//    C
//   C O
//  C O D
// C O D E

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "CODE";
    int length = strlen(str);
    int i, j;

    // Outer loop for rows
    for(i = 0; i < length; i++)
    {
        for(j = i; j < length - 1; j++)
        {
            printf(" ");
        }

        // Prints characters from 0 to i
        for(j = 0; j <= i; j++)
        {
            printf("%c", str[j]);
            if(j != i) printf(" "); // Spaces between characters
        }
        printf("\n");
    }
}
