// **Substring with Concatenation of All Words:** Write a function that takes a list of words and a string and checks if the string contains all the words in the list in any order.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define WORD_LEN 50

// Function to compare two word count arrays (expected vs seen)
bool compareWordCounts(int *count1, int *count2, int totalWords) 
{
    for (int i = 0; i < totalWords; i++) 
    {
        if (count1[i] != count2[i]) return false;
    }
    return true;
}

// Helper function to find the index of a word in the words list
int getWordIndex(char words[][WORD_LEN], int totalWords, const char *word) 
{
    for (int i = 0; i < totalWords; i++) 
    {
        if (strcmp(words[i], word) == 0)
            return i;
    }
    return -1;  // Return -1 if word not found
}

// Main function to find all starting indices of substrings that are a concatenation of all words
void findSubstringWithAllWords(char *s, char words[][WORD_LEN], int totalWords) 
{
    int wordLen = strlen(words[0]);         // Length of each word (all words assumed to be same length)
    int allWordsLen = wordLen * totalWords; // Total length of all words combined
    int sLen = strlen(s);                   // Length of the input string

    int expected[MAX_WORDS] = {0};          // Frequency map of expected word counts

    // Build the expected frequency map
    for (int i = 0; i < totalWords; i++) 
    {
        int index = getWordIndex(words, totalWords, words[i]);
        expected[index]++;
    }

    // Slide through the string with a window of size equal to total concatenated word length
    for (int i = 0; i <= sLen - allWordsLen; i++) 
    {
        int seen[MAX_WORDS] = {0};  // Frequency map of words seen in current window
        int j = 0;

        // Check if words in current window match the expected set
        for (; j < totalWords; j++) 
        {
            // Extract a word of length `wordLen` from the current position
            char word[wordLen + 1];
            strncpy(word, s + i + j * wordLen, wordLen);
            word[wordLen] = '\0';  // Null-terminate the substring

            // Find index of this word in original words list
            int index = getWordIndex(words, totalWords, word);
            if (index == -1) break;              // If word not in list, break
            seen[index]++;                       // Count this word
            if (seen[index] > expected[index])   // More occurrences than expected
                break;
        }

        // If all words matched, print the starting index
        if (j == totalWords) 
        {
            printf("%d ", i);
        }
    }
}

int main() 
{
    // Input string
    char s[] = "barfoothefoobarman";

    // List of words to check for (each of same length)
    char words[][50] = {"foo", "bar"};

    // Total number of words
    int totalWords = 2;

    // Function call
    findSubstringWithAllWords(s, words, totalWords);

    return 0;
}



