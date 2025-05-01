// **Print characters in a staircase pattern.**
// I  
// I N  
// I N T  
// I N T E  
// I N T E R

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "INTERN";
    int length = strlen(str);
    int i, j;

    // Outer loop for rows
    for(i = 0; i < length; i++)
    {
        // Inner loop for printing characters up to the current row
        for(j = 0; j <= i; j++)
        {
            printf("%c ", str[j]);
        }
        printf("\n");
    }
    return 0;
}