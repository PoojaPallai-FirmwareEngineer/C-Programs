// Write a function to compare two strings for equality

#include<stdio.h>
#include<string.h>

int stringcompare(const char *str1, const char *str2)
{
    while (*str1 && *str2)
    {
        // string contiunes till end
        if (*str1 != *str2)
        {
            return 1; // Not equal
        }
        *str1++;
        *str2++;
    }
    return *str1 == *str2;
}

int main()
{
    const char *str1 = "Hello";
    const char *str2 = "Hello";

    if (stringcompare(str1, str2))
    {
        printf("The strings are equal.\n");
    } 
    else 
    {
        printf("The strings are not equal.\n");
    }
}