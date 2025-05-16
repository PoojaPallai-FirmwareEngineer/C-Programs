// **Valid Palindrome (Ignoring Non-Alphanumeric Characters):** Write a function to check if a string is a valid palindrome, ignoring non-alphanumeric characters & case.
// Example:
// Enter the string:A man, a plan, a canal: Panama
// The string is palindrome

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Palindrome(char str[])
{
    int left = 0;
    int right = strlen(str) - 1;
    
    while(left < right)
    {
        while(left < right && !isalnum(str[left]))
        {
            left++;
        }
        
        while(left < right && !isalnum(str[right]))
        {
            right--;
        }
        
        // Convert the characters to lower case insentive
        if(tolower(str[left]) != tolower(str[right]))
        {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int main()
{
    char str[100];
    printf("Enter the string:");
    fgets(str, sizeof(str), stdin); // Read the input with spaces
    
    //remove the newline 
    str[strcspn(str, "\n")] = '\0';
    
    if(Palindrome(str))
    {
        printf("The string is palindrome\n");
    }
    else
    {
        printf("The string is not a Palindrome\n");
    }
}