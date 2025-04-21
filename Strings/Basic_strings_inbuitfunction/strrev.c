// Write a function to reverse a string

/*
strrev Function Availability: strrev is not a standard C function and is only available in 
specific compilers (like Turbo C or certain Microsoft compilers).
 In standard C environments, strrev is not defined, so attempting to use it may result in an error.
*/

#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    printf("Enter the string:");
    
    // Read a string input
    fgets(str, sizeof(str), stdin);

    // Remove a newline character
    str[strcspn(str, "\n")] = 0;

    // Check if strrev is available or use custom reversal if not
    #ifdef _MSC_VER // If using Microsoft Visual C++ compiler
        strrev(str);
    #else
        // Reverse string manually if strrev is unavailable
        int len = strlen(str);
        for (int i = 0; i < len / 2; i++) {
            char temp = str[i];
            str[i] = str[len - i - 1];
            str[len - i - 1] = temp;
        }
    #endif

    printf("Reverse string is %s\n", str);
}