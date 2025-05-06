// **Check if a String Can Be Formed by Repeating Substrings** - Write a function to check if a string is composed of a repeating substring.
// Example:
// Enter a string: ababab
// The string can be formed by repeating a substring.

#include <stdio.h>
#include <string.h>

int isRepeatingSubstring(char str[])
{
    int len = strlen(str);  // Get the length of the input string

    // Try all possible substring lengths from 1 to len/2
    for (int sublen = 1; sublen <= len / 2; sublen++)
    {
        // Only consider substring lengths that evenly divide the full string
        if (len % sublen == 0)
        {
            int repeatCount = len / sublen;  // How many times the substring needs to repeat

            // Extract the potential repeating substring of length 'sublen'
            char sub[sublen + 1];
            strncpy(sub, str, sublen);       // Copy the first 'sublen' characters
            sub[sublen] = '\0';              // Null-terminate the substring

            // Build the repeated string
            char repeated[len + 1];
            repeated[0] = '\0';              // Initialize empty string

            for (int i = 0; i < repeatCount; i++)
            {
                strcat(repeated, sub);       // Append the substring 'repeatCount' times
            }

            // Check if the constructed string matches the original
            if (strcmp(repeated, str) == 0)
            {
                return 1;  // Match found — the string can be formed by repeating a substring
            }
        }
    }

    return 0;  // No repeating pattern found
}


int main()
{
    char str[100];

    // User input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;  // Remove newline if present

    // Check if the string can be formed by repeating a substring
    if (isRepeatingSubstring(str)) 
    {
        printf("The string can be formed by repeating a substring.\n");
    } 
    else 
    {
        printf("The string cannot be formed by repeating a substring.\n");
    }

    return 0;
}