// **Find the longest common prefix among an array of strings.** 

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100 // Maximum length for each string

// Function to find the longest common prefix among n strings
char* longestCommonPrefix(char arr[][MAX_LEN], int n) 
{
    static char prefix[MAX_LEN];

    // Edge case: no strings
    if (n == 0) return "";

    // Start with the first string as the prefix
    strcpy(prefix, arr[0]);

    for (int i = 1; i < n; i++) 
    {
        int j = 0;

        // Compare characters of prefix and arr[i] until they mismatch
        while (prefix[j] && arr[i][j] && prefix[j] == arr[i][j]) 
        {
            j++;
        }

        // Truncate prefix where mismatch occurred
        prefix[j] = '\0';

        // If at any point prefix becomes empty, no common prefix exists
        if (prefix[0] == '\0') 
        {
            return "";
        }
    }

    return prefix;
}


int main() 
{
    char arr[3][100] = {"flower", "flow", "flight"};
    int n = 3;

    printf("Longest Common Prefix: \"%s\"\n", longestCommonPrefix(arr, n));
    
    return 0;
}
