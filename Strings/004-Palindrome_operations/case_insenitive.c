// **Case-Insensitive Palindrome Check:** Write a function to check if a string is a palindrome while ignoring case.
// **Palindrome Check Without Extra Space:** Write a function to check if a string is a palindrome without using extra space.
// Enter the string:racecar
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
    scanf("%99s", str);
    
    if(Palindrome(str))
    {
        printf("The string is palindrome\n");
    }
    else
    {
        printf("The string is not a Palindrome\n");
    }
}