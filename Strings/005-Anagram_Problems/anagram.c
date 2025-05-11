/*
 * Program: Check if two strings are anagrams of each other.
 * Write a function to check if two strings are valid anagrams of each other without using built-in sort functions.
 * 
 * Concept:
 * Anagrams are words or phrases formed by rearranging the letters of another word or phrase,
 * using all the original letters exactly once. For two strings to be anagrams:
 * 
 * 1. They must contain the same characters in the same quantity.
 * 2. They can differ in the order of characters.
 * 
 * Examples:
 * - "listen" and "silent" are anagrams because they contain the same letters (l, i, s, t, e, n),
 *   just arranged differently.
 * - "triangle" and "integral" are also anagrams for the same reason.
 * 
 * Non-Examples:
 * - "hello" and "world" are not anagrams because they don’t contain the same characters.
 * - "cat" and "acts" are also not anagrams because "acts" has an extra 's'.
 * 
 * Anagrams are commonly used in puzzles, cryptography, and word games.
 * 
 * Return Values:
 * The function `areAnagrams` is designed to return an integer:
 * - return 0 generally means success (true), indicating that the two strings are anagrams.
 * - return 1 means failure (false), indicating that the two strings are not anagrams.
 * 
 * This approach keeps the function in line with standard programming practices, where:
 * - true signifies a successful condition (anagrams),
 * - false signifies an unsuccessful condition (not anagrams).
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool areAnagrams(char *str1, char *str2)
{
    //If length are different they are not anagrams
    if (strlen(str1) != strlen(str2))
    {
        return false;
    }

    // Initialise an array to count characters 
    int count[256] = {0};

    // Count characters in str1 and subtract for characters in str2
    for (int i = 0; str1[i] != '\0'; i++)
    {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }

    // Checl if all counts are zero
    for(int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main() {
    char str1[] = "listen";
    char str2[] = "silent";

    if (areAnagrams(str1, str2)) 
    {
        printf("The strings \"%s\" and \"%s\" are anagrams.\n", str1, str2);
    } 
    else 
    {
        printf("The strings \"%s\" and \"%s\" are not anagrams.\n", str1, str2);
    }

    return 0;
}