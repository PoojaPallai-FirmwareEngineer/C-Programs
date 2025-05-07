// **Write a program to sort the words in a sentence in descending order.**
// Example:
// Enter a sentence: this is a simple test
// Sorted words in descending order:
// this test simple is a 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD        100
#define MAX_WORD_LEN    50

int splitsentence(char *sentence, char words[MAX_WORD][MAX_WORD_LEN])
{
    int count = 0;
    char *token = strtok(sentence, " ");
    
    while(token != NULL)
    {
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

void sortdescending(char words[MAX_WORD][MAX_WORD_LEN], int count)
{
    char temp[MAX_WORD_LEN];
    //int j = 0;
    
    for( int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - i - 1; j++)
        {
            if(strcmp(words[j], words[j + 1]) < 0)
            {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
}

int main()
{
    char sentence[MAX_WORD_LEN * MAX_WORD];
    char words[MAX_WORD][MAX_WORD_LEN];
    
    // Input sentence from user
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    // Remove newline character if present
    sentence[strcspn(sentence, "\n")] = '\0';

    // Split sentence into words
    int wordCount = splitsentence(sentence, words);

    // Sort words in descending order
    sortdescending(words, wordCount);

    // Print sorted words
    printf("\nSorted words in descending order:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}

