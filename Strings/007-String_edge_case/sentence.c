// **Find Words in a Sentence** - Write a function that splits a sentence into words and returns a list of words.
// Example:
// Enter a sentence: I am pooja pallai A firmware developer
// Words in the sentence:
// I
// am
// pooja
// pallai
// A
// firmware
// developer

#include <stdio.h>
#include <string.h>

#define MAX_WORDS       100
#define MAX_WORDS_LEN   50

int splitSentenceIntoWords(char sentence[], char words[][MAX_WORDS_LEN])
{
    int i = 0;
    char *token = strtok(sentence, " "); // tokenize sentence by space
    
    while(token != NULL)
    {
        strcpy(words[i], token); // Copy each word into words array
        i++;
        token = strtok(NULL, " ");
    }
    
    return i;
}

int main()
{
    char sentence[500];
    char words[MAX_WORDS][MAX_WORDS_LEN];
    int numwords;
    
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = 0;  // Remove newline if present

    // Split the sentence into words
    numwords = splitSentenceIntoWords(sentence, words);

    // Display the words
    printf("Words in the sentence:\n");
    for (int i = 0; i < numwords; i++) 
    {
        printf("%s\n", words[i]);
    }

    return 0;
}
