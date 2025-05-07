// Write a function to compare two strings for equality

#include<stdio.h>
#include<string.h>

int stringcompare(const char *str1, const char *str2)
{
    // logic can be done 
    // 1. while loop with pointer
    // 2. for loop with pointer
    // 3. while loop with index
    // 4. for loop with index
    // 5. recursion

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