/*
Program: 
1. Write a function to find the first unique character in a string.
2. Write a function to find the most frequent character in a string.

Function: first_unique_character
- This function finds the first unique character in a given string.
  
Steps:
1. Initialize a count array of size 256 to accommodate all possible ASCII characters.
2. Iterate through the string to fill the count array with character frequencies.
3. In a second loop, check the count array for the first character with a count of 1.
4. Return the first unique character found, or return '\0' if no unique character exists.

Function: most_frequent_character
- This function finds the most frequent character in a given string.

Steps:
1. Initialize a count array of size 256 to keep track of character occurrences.
2. Iterate through the string to fill the count array.
3. After counting, iterate through the count array to find the character with the maximum count.
4. Return the character with the maximum frequency, or return '\0' if the string is empty.
*/

#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 256

char first_unique_character(const char *s)
{
    // Step1: Count array for ASCII characters initialized to 0
    int count[ASCII_SIZE] = {0};

    // Fill the count array
    for(int i = 0; s[i] != '\0'; i++)
    {
        // Increment the count for each character
        count[(unsigned char)s[i]]++;
    }

    // Find the first unique character
    for(int i = 0; s[i] != '\0'; i++)
    {
        // Check if the count 1
        if (count[(unsigned char)s[i]] == 1)
        {
            return s[i]; // Return the first unqiue character
        }
    }

    return '\0'; // No unique character found
}

char most_frequent_character(const char *s)
{
    // Step1: Count array for ASCII characters initialized to 0
    int count[ASCII_SIZE] = {0};
    char max_char = '\0'; // To store the most frequent character
    int max_count = 0; // To store the maximum count

    // Fill the count array
    for(int i = 0; s[i] != '\0'; i++)
    {
        // Increment the count for each character
        count[(unsigned char)s[i]]++;
    }

    // Fill the most frequent character
    for(int i = 0; i < ASCII_SIZE; i++)
    {
        if (count[i] > max_count)
        {
            max_count = count[i];
            max_char = (char)i;
        }
    }
    return max_char;
}

int main() {
    const char *str = "swiss";  

    // Finding the first unique character
    char first_unique = first_unique_character(str);
    if (first_unique != '\0') 
    {
        printf("The first unique character is: '%c'\n", first_unique);
    } 
    else 
    {
        printf("No unique character found.\n");
    }

    // Finding the most frequent character
    char most_frequent = most_frequent_character(str);
    if (most_frequent != '\0') 
    {
        printf("The most frequent character is: '%c'\n", most_frequent);
    } 
    else 
    {
        printf("The string is empty.\n");
    }

    return 0;
}