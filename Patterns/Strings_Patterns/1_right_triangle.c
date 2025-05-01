// **Print a given string in a right-aligned triangular pattern.**
//     M
//    My
//   MyN
//  MyNa
// MyNam

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "MyNam";
    int length = strlen(str);
    int i, j;

    // Outer loop for rows
    for(i = 1; i <= length; i++)
    {
        // Print spaces to right align
        for(j = 0; j < length - i; j++)
        {
            printf(" ");
        }

        // Print substring of the first i characters
        for(j = 0; j < i; j++)
        {
            printf("%c", str[j]);
        }
        printf("\n");
    }
    return 0;
}