// **Edit Distance:** Write a function to calculate the minimum number of operations required to convert one string to another (using insert, delete, replace).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c)
{
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int mineditdistance(char* word1, char* word2)
{
    int m = strlen(word1);
    int n = strlen(word2);

    // create a 2d array to store results of subproblems
    int dp[m + 1][n + 1];

    // fill dp in bottom up manner
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            // If the first string is empty, only option is to insert all characters of second string
            if(i == 0)
                dp[i][j] = j; // min operation = j
            
            // If the second string is empty, only option is to insert all characters of second string
            else if(j == 0)
                dp[i][j] = i; // min operation = i
            
            // If last characters are same, ignore last char & recur for remaining string
            else if(word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            
            // If last characters is different, consider all possibilites and find the minimum
            else
            {
                dp[i][j] = 1 + min(dp[i][j - 1],      // Insert
                                   dp[i - 1][j],      // Remove
                                   dp[i - 1][j - 1]); // Replace
            }
        }   
    }
    return dp[m][n];
}

int main() {
    char word1[] = "sitting";
    char word2[] = "kitten";

    printf("Minimum edit distance: %d\n", mineditdistance(word1, word2));
    
    return 0;
}