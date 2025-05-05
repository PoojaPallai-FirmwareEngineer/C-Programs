// **Longest Palindromic Substring:** Write a function to find the longest palindromic substring in a string.
// Example: 
// Enter the string:banana
// The longest palindrome:nana

#include <stdio.h>
#include <string.h>

int expandAroundCentre(char *str, int left, int right)
{
    while(left >= 0 && right < strlen(str) && str[left] == str[right])
    {
        left--;
        right++;
    }
    return right - left - 1; // Length of palindrome
}

void palindrome(char *str, char *result)
{
    int len = strlen(str);
    int maxLength = 0;
    int start = 0;
    
    for(int i = 0; i < len; i++)
    {
        // Odd Palindrome
        int len1 = expandAroundCentre(str, i, 1);
    
        // Even Palindrome 
        int len2 = expandAroundCentre(str, i, 1 + 1);
        
        int maxLen = (len1 > len2) ? len1: len2;
        
        // Update the Palindrome 
        if(maxLen > maxLength)
        {
            maxLength = maxLen;
            start = i - (maxLength - 1) / 2;
        }
    }
    // Copy the longest palindrome to result
    strncpy(result, str + start, maxLength);
    result[maxLength] = '\0';
}

int main()
{
    char str[100], result[100];
    
    printf("Enter the string:");
    scanf("%99s", str);
    
    palindrome(str, result);
    
    printf("The longest palindrome:%s\n", result);
}
