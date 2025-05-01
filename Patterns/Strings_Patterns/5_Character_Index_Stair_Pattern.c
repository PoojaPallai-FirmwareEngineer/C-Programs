// **Character Index Stair Pattern**
// H
// E H
// L E H
// L L E H
// O L L E H

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "HELLO";
    int length = strlen(str);
    int i, j;

    // Outer loop to handle each rows (stair step)
    for(i = 0; i < length; i++)
    {
        // Inner loop for printing characters in reverse order
        // It starts from current row index i and prints backwards
        for(j = i; j >= 0; j--)
        {
            printf("%c ", str[j]);
        }
        printf("\n");
    }
    return 0;
}