// **Longest Increasing Subsequence in a String:** Write a function to find the longest increasing subsequence in a string.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the Longest Increasing Subsequence (LIS) in a string
char* longestincreasingsubsequence(const char *str)
{
    int n = strlen(str); // Length of the input string

    int lis[n];   // Array to store lengths of LIS ending at each index
    int prev[n];  // Array to track previous indices to reconstruct the LIS

    // Initialize LIS lengths and previous indices
    for(int i = 0; i < n; i++)
    {
        lis[i] = 1;      // Each character is an LIS of length 1 by itself
        prev[i] = -1;    // No previous character yet
    }

    // Build the LIS array using dynamic programming
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            // If current character is greater than a previous one
            // and including it increases LIS length
            if(str[i] > str[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1; // Update LIS length
                prev[i] = j;         // Track the index to reconstruct sequence
            }
        }
    }

    // Find the index where the LIS ends (maximum value in lis[])
    int maxIndex = 0;
    for(int i = 1; i < n; i++)
    {
        if(lis[i] > lis[maxIndex])
        {
            maxIndex = i;
        }
    }

    // Get the length of the LIS and allocate memory for the result string
    int length = lis[maxIndex];
    char* result = (char *)malloc(length + 1); // +1 for null terminator
    result[length] = '\0'; // Null-terminate the string

    // Reconstruct the LIS by backtracking through the prev[] array
    int k = length - 1;
    for(int i = maxIndex; i >= 0; i = prev[i])
    {
        result[k--] = str[i]; // Fill the result string from end to start
        if(prev[i] == -1) break; // If no previous index, we're done
    }

    return result; // Return the result string containing LIS
}


int main() {
    const char *input = "acbdgeh";
    char *lis = longestincreasingsubsequence(input);
    printf("Longest Increasing Subsequence: %s\n", lis);
    free(lis);
    return 0;
}
