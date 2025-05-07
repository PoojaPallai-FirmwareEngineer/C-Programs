/* 
1. Write a function to find the first occurrence of a substring in a string
2. Write a function to count the occurrences of a particular substring in a string.
*/

#include <stdio.h>
#include <string.h>

char* findsubstring(const char *str, const char *substr)
{
    const char *strptr;
    const char *subptr;
    
    // Loop through each character in `str`
    while (*str) 
    {
        strptr = str;
        subptr = substr;

        // Check if the substring matches starting from the current position
        while (*strptr && *subptr && *strptr == *subptr) 
        {
            strptr++;
            subptr++;
        }

        // If the end of `substr` is reached, it means we found a match
        if (*subptr == '\0') 
        {
            return (char*)str;
        }

        // Move to the next character in `str` and try again
        str++;
    }

    // No match found
    return NULL;
}

int countSubstringoccurrences(const char *str, const char *sub)
{
    int count = 0;
    int subLen = strlen(sub);

    // Iterate through the main string
    for (const char *p = str; (p = strstr(p, sub)) != NULL; p += subLen)
    {
        count++; // Found a match increment the count;
    }

    return count;
}


int main()
{
    const char *str = "Hello, welcome to the world of C programming!";
    const char *substr = "welcome";

    const char *str1 = "Hello World, Hello Universe";
    const char *sub1 = "Hello";

    char *result = findsubstring(str, substr);

    if (result) {
        printf("Substring found at position: %ld\n", result - str);
    } 
    else 
    {
        printf("Substring not found.\n");
    }

    int count = countSubstringoccurrences(str1, sub1);
    printf("The substring '%s' occurs %d times in the string.\n", sub1, count);

    return 0;
}
