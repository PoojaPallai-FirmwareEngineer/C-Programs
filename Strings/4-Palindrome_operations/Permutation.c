// **Check if String is a Permutation of a Palindrome:** Write a function to check if a string is a permutation of a palindrome.
// Example:
// Enter a string: Tact Coa
//The string is a permutation of a palindrome.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define CHAR_SIZE      256

int permutataions(char *str)
{
    int oddcount = 0;
    char char_count[CHAR_SIZE] = {0};
    
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ') // Ignore spaces
        {
            char ch = tolower(str[i]); // convert to lower case
            char_count[ch]++;
        }
    }
    
    // To check how many characters are oddcount
    for(int i = 0; i < CHAR_SIZE; i++)
    {
        if(char_count[i] % 2 != 0)
        {
            oddcount++;
        }
    }
    
    // A palindrome permutation must have at most one odd character count
    return(oddcount <= 1);
}


int main() 
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // Read input string with spaces

    // Remove trailing newline (if present)
    str[strcspn(str, "\n")] = '\0';

    if (permutataions(str)) 
    {
        printf("The string is a permutation of a palindrome.\n");
    } 
    else 
    {
        printf("The string is NOT a permutation of a palindrome.\n");
    }

    return 0;
}