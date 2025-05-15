// **Longest Repeating Substring:** Write a function to find the longest repeating substring in a string.

#include <stdio.h>
#include <string.h>

// Helper function to find length of the longest common prefix of two substrings
int longestCommonPrefix(char *s1, char *s2) 
{
    int len = 0;
    while (*s1 && *s2 && *s1 == *s2) 
    {
        len++;
        s1++;
        s2++;
    }
    return len;
}

// Main function to find the longest repeating substring
void longestRepeatingSubstring(char *str) 
{
    int n = strlen(str);
    int maxLen = 0;
    int startIndex = 0;

    // Compare each suffix with every other suffix
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            int len = longestCommonPrefix(&str[i], &str[j]);

            // Update if we find a longer repeating substring
            if (len > maxLen) 
            {
                maxLen = len;
                startIndex = i;
            }
        }
    }

    // If a repeating substring is found, print it
    if (maxLen > 0) 
    {
        printf("Longest Repeating Substring: ");
        for (int i = startIndex; i < startIndex + maxLen; i++) 
        {
            putchar(str[i]);
        }
        printf("\n");
    } 
    else 
    {
        printf("No repeating substring found.\n");
    }
}

int main() 
{
    char str[] = "banana";
    longestRepeatingSubstring(str);
    return 0;
}
