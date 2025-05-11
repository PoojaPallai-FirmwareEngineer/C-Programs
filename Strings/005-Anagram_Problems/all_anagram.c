/*

Find All Anagrams in a String: Write a function to find all anagrams of a word within a string.

1. Define a Helper Function to Check Anagrams:
   - Create a function that takes two strings as input.
   - Use a frequency count (e.g., an array of size 256 for ASCII) to count characters in the first string.
   - Decrease the count based on the characters in the second string.
   - If all frequency counts are zero, the two strings are anagrams.

2. Use Sliding Window Technique:
   - Determine the length of the main string and the target word.
   - Slide a window of size equal to the length of the target word over the main string.
   - For each substring of the main string with window size:
       - Extract the substring.
       - Use the helper function to check if this substring is an anagram of the target word.
       - If it is, note the starting index or print the substring.

3. Edge Case Handling:
   - If the target word is longer than the main string, return immediately as no anagram is possible.
*/

#include <stdio.h>
#include <string.h>

int areanagrams(char *str1, char *str2)
{
    // Assume ASCII characters
    int count[256] = {0};

    // Count frequency of characters of str1
    for(int i = 0; str1[i] != '\0'; i++)
    {
        count[str1[i]]++;
    }

    // Subtract frequency of characters of str2
    for(int i = 0; str2[i] != '\0'; i++)
    {
        count[str2[i]]--;
    }

    // Check if all elements in count array are zero
    for(int i = 0; i < 256; i++)
    {
        if(count[i] != 0)
        {
            return 0; // Not anagrams
        }
    }

    return 1; // Anagrams
}

// Function to find all anagrams of a word within a string
void findallanagrams(char *str, char *word)
{
    int str_length = strlen(str);
    int word_length = strlen(word);

    // Check for edge cases
    if (word_length > str_length)
    {
        printf("No anagrams found\n");
        return;
    }

    // Iterate through the string with a sliding window
    for (int i = 0; i <= str_length - word_length; i++)
    {
        char substring[word_length + 1];
        strncpy(substring, &str[i], word_length);
        substring[word_length] = '\0'; // Null terminate the substring

        // Check if current substring is an angram of the word
        if(areanagrams(substring, word))
        {
            printf("Anagram found at index %d: %s\n", i, substring);
        }
    }
}

int main() 
{
    char str[] = "cbaebabacd";
    char word[] = "abc";
    
    printf("String: %s\n", str);
    printf("Word: %s\n", word);
    
    findallanagrams(str, word);
    
    return 0;
}
