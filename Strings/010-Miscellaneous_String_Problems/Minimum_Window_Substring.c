// **Find the Minimum Window Substring:** Write a function that finds the smallest window in a string which contains all characters of another string.

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_CHAR 256  // Define the maximum number of characters (ASCII limit)

// Function to find the minimum window substring
char* minwindow(char* s, char* t)
{
    int start = 0;           // Left boundary of the sliding window
    int count = 0;           // Total characters matched so far
    int startIndex = -1;     // Start index of the minimum window found
    int minlen = INT_MAX;    // Length of the minimum window

    int lenS = strlen(s);    // Length of input string s
    int lenT = strlen(t);    // Length of target string t

    // Edge case: If s or t is empty or t is longer than s, return empty string
    if(lenS == 0 || lenT == 0 || lenS < lenT)
        return "";

    // Frequency maps for characters in t and the current window in s
    int hashT[MAX_CHAR] = {0};  // Frequency of characters in t
    int hashS[MAX_CHAR] = {0};  // Frequency of characters in the current window

    // Count all characters in t and store their frequencies in hashT
    for(int i = 0; i < lenT; i++)
        hashT[t[i]]++;
    
    // Traverse the main string s with a sliding window using 'end'
    for(int end = 0; end < lenS; end++)
    {
        char ch = s[end];    // Current character
        hashS[ch]++;         // Update current window's frequency

        // If the character is part of t and we haven’t used more than required
        if (hashS[ch] <= hashT[ch])
            count++;         // Increment the match count
        
        // When all characters of t are matched in the window
        if(count == lenT)
        {
            // Try to shrink the window from the start
            while(hashS[s[start]] > hashT[s[start]] || hashT[s[start]] == 0)
            {
                if(hashS[s[start]] > hashT[s[start]])
                    hashS[s[start]]--;   // Decrease frequency in window if extra

                start++;  // Move the left boundary forward
            }

            int windowlen = end - start + 1;  // Calculate current window length
            if(windowlen < minlen)
            {
                minlen = windowlen;      // Update minimum length found
                startIndex = start;      // Update starting index of minimum window
            }
        }
    }

    // If no valid window is found
    if (startIndex == -1)
        return "";

    // Create and return the result substring from the original string
    static char result[1000];                 // Static to return local memory
    strncpy(result, s + startIndex, minlen);  // Copy minimum window substring
    result[minlen] = '\0';                    // Null-terminate the result

    return result;
}

int main() 
{
    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";

    char* result = minwindow(s, t);
    if (strlen(result) > 0)
        printf("Minimum window substring: %s\n", result);
    else
        printf("No such window exists.\n");

    return 0;
}