/*
Program: Write a function to check if two strings are valid anagrams of each other using built-in sort functions.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int comparechars(const void *a, const void *b)
{
    // Comparison function for qsort
    return *(char *)a - *(char *)b;
}

// To check if two strings are anagrams
bool areAnagrams(char *str1, char *str2)
{
    //If length are different they are not anagrams
    if (strlen(str1) != strlen(str2))
    {
        return false;
    }

    // Sort both strings
    qsort(str1, strlen(str1), sizeof(char), comparechars);
    qsort(str2, strlen(str2), sizeof(char), comparechars);

    // Compare sorted strings
    return strcmp(str1, str2) == 0;
}

int main() 
{
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
