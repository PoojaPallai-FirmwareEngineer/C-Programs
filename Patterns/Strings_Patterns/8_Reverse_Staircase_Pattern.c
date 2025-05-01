// **Reverse Staircase Pattern**
// H E L L O
// H E L L
// H E L
// H E
// H

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "HELLO";
    int length = strlen(str);
    int i, j;

    // Outer loop to handle each row (stair step)
    for(i = length; i > 0; i--)
    {
        // Inner loop for printing characters from the start to the current row size
        for(j = 0; j < i; j++)
        {
            printf("%c ", str[j]);
        }
        printf("\n");
    }
    return 0;
}