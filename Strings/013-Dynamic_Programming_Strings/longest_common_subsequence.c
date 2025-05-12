#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonSubsequence(const char *s1, const char *s2)
{
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a DP table to store lengths of LCS for substrings
    int dp[m + 1][n + 1];

    // Fill the DP table using bottom-up dynamic programming
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0; // Base case: empty string comparison
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1]; // If characters match
            else
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] 
                           ? dp[i - 1][j] : dp[i][j - 1]; // Take the max
        }
    }

    // Get the length of the LCS from the last cell
    int index = dp[m][n];

    // Allocate memory for LCS string (+1 for null terminator)
    char *lcs = (char *)malloc(index + 1);
    lcs[index] = '\0'; // Null terminate the string

    // Trace back through the DP table to reconstruct the LCS
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            // If characters match, include in LCS and move diagonally
            lcs[--index] = s1[i - 1];
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--; // Move up
        else
            j--; // Move left
    }

    return lcs; // Return the final LCS string
}

int main() 
{
    const char *str1 = "AGGTAB";
    const char *str2 = "GXTXAYB";

    // Call the LCS function
    char *lcs = longestCommonSubsequence(str1, str2);

    // Print the result
    printf("Longest Common Subsequence: %s\n", lcs);

    // Free the dynamically allocated memory
    free(lcs);

    return 0;
}
