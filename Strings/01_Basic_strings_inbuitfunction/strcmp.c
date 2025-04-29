// Write a function to compare two strings for equality

#include<stdio.h>
#include<string.h>

int stringcompare(const char *str1, const char *str2)
{
    return strcmp(str1, str2) == 0;
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