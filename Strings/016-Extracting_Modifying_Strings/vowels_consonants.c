// **Count the number of vowels and consonants in a given string.**
// Example:
// Enter a string: hello world
// Number of vowels: 3
// Number of consonants: 7

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countVowelsConsonants(char str[], int *vowelscount, int *consonantscount)
{
    *vowelscount = 0;
    *consonantscount = 0;
    
    for(int i = 0; str[i] != '\0'; i++)
    {
        // convert lowercase for easy checking
        char ch = tolower(str[i]);
        
        if(ch >= 'a' && ch <= 'z')
        {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                (*vowelscount)++;
            }
            else
            {
                (*consonantscount)++;
            }
        }
    }
}

int main()
{
    char str[100];
    int vowels, consonants;

    // Input string from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Count vowels and consonants
    countVowelsConsonants(str, &vowels, &consonants);

    // Print results
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
}