// **Palindrome Pyramid**
//        A
//       ABA
//      ABCBA
//     ABCDCBA
//    ABCDEDCBA

#include <stdio.h>

int main()
{
    int n = 5;

    // Outer loop for each row
    for(int i = 1; i <= n; i++)
    {
        // Leading spaces for pyramid shape 
        for(int j = i; j < n; j++)
        {
            printf(" "); // Print space for alignment
        }

        // Print the left side of the Palindrome(Increasing part)
        for(int j = 1; j <= i; j++)
        {
            printf("%c", 'A' + j - 1); // Prints the characters from 'A' onwards
        }

        // Print the right side of the Palindrome(decreasing part)
        for(int j = i - 1; j >= 1; j--)
        {
            printf("%c", 'A' + j - 1); // Prints the characters in reverse order
        }
        printf("\n");
    }
    return 0;
}