// Write a function to check if a string contains only digits

#include <stdio.h>
#include<ctype.h>

int containsonlydigits(const char *str)
{
    //Returns 0 if the string is NULL or empty
    if ((str == NULL ) || *str == '\0')
    {
        return 0;
    }

    // Check each character
    while(*str)
    {
        // 2 ways to write this line without using inbuilt function
        // if (!isdigit((unsigned char)*str))
        if (*str < '0' || *str > '9')
        {
            return 0; // Non-digit character found
        }
        str++;
    }
    return 1; // Only string in the string 
}

int main() {
    const char *testStr = "1234abc56";

    if (containsonlydigits(testStr)) 
    {
        printf("The string contains only digits.\n");
    } 
    else 
    {
        printf("The string contains non-digit characters.\n");
    }
    return 0;
}
