// **Longest Substring Without Repeating Characters:** Write a function to find the longest substring without repeating characters.

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256  // Total possible ASCII characters

void longestUniqueSubstring(char *str) 
{
    int n = strlen(str);
    int lastIndex[MAX_CHAR];  // Array to store last index of characters
    for (int i = 0; i < MAX_CHAR; i++)
        lastIndex[i] = -1;     // Initialize all characters as not seen

    int maxLen = 0;            // Length of longest unique substring
    int start = 0;             // Start index of current window
    int maxStart = 0;          // Start index of the longest substring

    for (int end = 0; end < n; end++) 
    {
        char ch = str[end];

        // If character was seen and is inside the current window
        if (lastIndex[ch] >= start) 
        {
            start = lastIndex[ch] + 1;  // Move start right after the last duplicate
        }

        lastIndex[ch] = end;            // Update last seen index of current character

        // Update max length if needed
        if (end - start + 1 > maxLen) 
        {
            maxLen = end - start + 1;
            maxStart = start;
        }
    }

    // Print the result
    printf("Longest Substring Without Repeating Characters: ");
    for (int i = maxStart; i < maxStart + maxLen; i++)
    {
        putchar(str[i]);
    }
    printf("\nLength: %d\n", maxLen);
}

// Example usage
int main() 
{
    char str[] = "abcabcbb";
    longestUniqueSubstring(str);
    return 0;
}
