// **Group Anagrams:** Write a function that groups anagrams from a list of strings.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS                 100
#define MAX_WORD_LENGTH           100
#define MAX_GROUPS                100

typedef struct 
{
    char key[MAX_WORD_LENGTH];      // Sorted version of the word
    char *words[MAX_WORDS];         // Original words
    int count;
}AnagramGroup;

void sortString(char *str, char *sorted)
{
    strcpy(sorted, str);
    int len = strlen(sorted);
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if(sorted[i] > sorted[j])
            {
                char temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
}

void groupAnagrams(char *words[], int wordCount)
{
    AnagramGroup groups[MAX_GROUPS];  // Array to store groups of anagrams
    int groupcount = 0;               // Number of groups created so far

    // Loop through each word
    for(int i = 0; i < wordCount; i++)
    {
        char sorted[MAX_WORD_LENGTH];
        sortString(words[i], sorted);  // Sort the current word to get the key

        int found = 0;  // Flag to check if a group for this key already exists

        // Search through existing groups to see if one matches this sorted key
        for(int j = 0; j < groupcount; j++)
        {
            if (strcmp(groups[j].key, sorted) == 0)
            {
                // If found, add the original word to the existing group
                groups[j].words[groups[j].count++] = words[i];
                found = 1;
                break;  // No need to check further
            }
        }

        // If no group with this key exists, create a new group
        if (!found)
        {
            strcpy(groups[groupcount].key, sorted);    // Set the key
            groups[groupcount].words[0] = words[i];     // Add the word to the group
            groups[groupcount].count = 1;               // Initialize count
            groupcount++;                               // Increment the number of groups
        }
    }

    // Print all grouped anagrams
    printf("Grouped Anagrams:\n");
    for(int i = 0; i < groupcount; i++)
    {
        printf("[ ");
        for(int j = 0; j < groups[i].count; j++)
        {
            printf("%s ", groups[i].words[j]);  // Print each word in the group
        }
        printf("]\n");
    }
}

int main() 
{
    // Sample input
    char *words[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int wordCount = sizeof(words) / sizeof(words[0]);

    groupAnagrams(words, wordCount);

    return 0;
}