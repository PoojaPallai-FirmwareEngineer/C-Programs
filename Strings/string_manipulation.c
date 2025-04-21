/*
Write a function to remove duplicate characters from a string.
    NOTE: It will remove the duplicates and print the str without duplicate words

Write a function to remove all whitespace from a string.
    NOTE: It removes all the space and joint sentence/words.

Write a function to replace all occurrences of a character in a string.
    NOTE: It will replace the string that matches old characters with new charcters

Write a function to convert a string to lowercase or uppercase.
Write a function to shift all spaces in a string to the end without changing the order of other characters.
Write a function to reverse the words in a string (e.g., "Hello World" -> "World Hello")
Write a function to remove vowels from a string.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removeDuplicates(char *str)
{
    int hash[256] = {0}; // Hash table to track characters (ASCII range)
    int currentIndex = 0; //Index to replace non-duplicate characters
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        // Only add the character if it hasnot appeared before
        if (hash[(unsigned char)str[i]] == 0)
        {
            hash[(unsigned char)str[i]] = 1;
            str[currentIndex++] = str[i];
        }
    }

    // Null terminate the string to mark the end
    str[currentIndex] = '\0';
}

void removeWhitespace(char *str)
{
    int currentIndex = 0; // Position to place non-whitespace characters
    int i = 0;

    // Loop through each character in the string
    while (str[i] != '\0')
    {
        //Check if the character is not a whitespace (space, tab, newline)
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            str[currentIndex++] = str[i]; // Move non whitespace character 
        }
        i++;
    }

    // Null terminate the modified string 
    str[currentIndex] = '\0';
}

void replaceCharacter(char *str, char oldChar, char newChar)
{
    int i = 0;

    // Loop through each character in the string
    while (str[i] != '\0')
    {
        // If the current character matches oldChar replace it with newChar
        if (str[i] == oldChar)
        {
            str[i] = newChar;
        }
        i++;
    } 
}

void toLowercase(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        // Check if the character is uppercase
        if ( str[i] >= 'A' && str[i] <= 'Z')
        {
            // Convert to lowercase
            str[i] = str[i] + ('a' - 'A');
        }
        i++;
    }
}

void toUppercase(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        // Check if the character is lowercase
        if ( str[i] >= 'a' && str[i] <= 'z')
        {
            // Convert to lowercase
            str[i] = str[i] - ('a' - 'A');
        }
        i++;
    }
}

void shiftSpacesToEnd (char *str)
{
    int currentIndex = 0; // Index to store non spce characters
    int i = 0;

    // Move all the non space characters to the beginning of the string
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            str[currentIndex++] = str[i];
        }
        i++;
    }

    // Fill the remaining positions with spaces
    while (currentIndex < i)
    {
        str[currentIndex++] = ' ';
    } 
}

void reverse(char *start, char *end)
{
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reversewords(char *str)
{
    int length = strlen(str);

    // Reverse the entire string
    reverse(str, str + length - 1);

    // Reverse each word in the reversed the string
    char *start = str;
    for (int i = 0; i <= length; i++)
    {
        // When we reach a space or end of string reverse of the word
        if (isspace(str[i]) || str[i] == '\0')
        {
            reverse(start, str + i - 1);
            start = str + i + 1;
        }
    }
}

void removevowels(char *str)
{
    int i, j = 0;
    int length = strlen(str);

    for(i = 0; i < length; i++)
    {
        // Check if the character is a vowels
        char ch = tolower(str[i]);
        if(ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
        {
            // If its not a vowelcopy it to the current positions
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int main()
{
    // Remove Duplicates
    char str[] = "programming";
    // Remove whitespace
    char str1[] = "This is a \t test\n string with \t whitespace."; 
    // Replace characters
    char str2[] = "hello world";
    char oldChar = 'o';
    char newChar = 'a';
    // To convert lowercase & uppercase
    char str3[] = "Hello World";
    // Shift all spaces in a string to the end
    char str4[] = "Move all spaces to the end";
    
    // Remove duplicates
    printf("Original string: %s\n", str);
    removeDuplicates(str);
    printf("String after removing duplicates: %s\n", str);

    // Remove whitespace
    printf("Original String: \"%s\"\n", str1);
    removeWhitespace(str1);
    printf("String after removing whitespace: \"%s\"\n", str1);

    // Replace characters
    printf("Original String: %s\n", str2);
    replaceCharacter(str2, oldChar, newChar);
    printf("String after replacement: %s\n", str2);

    // Convert to lowercase & uppercase
    printf("Original String: %s\n", str3);
    toLowercase(str3);
    printf("Lowercase: %s\n", str3);
    toUppercase(str3);
    printf("Uppercase: %s\n", str3);

    // Shift all spaces in a string to the end
    printf("Original String: \"%s\"\n", str4);
    shiftSpacesToEnd(str4);
    printf("String after shifting spaces to the end: \"%s\"\n", str4);

    // Reverse words of the strings
    printf("Original string: %s\n", str3);
    reversewords(str3);
    printf("Reversed words: %s\n", str3);

    // Remove the vowels
    printf("Original string: %s\n", str3);
    removevowels(str3);
    printf("String after removing vowels: %s\n", str3);

    return 0;
}
