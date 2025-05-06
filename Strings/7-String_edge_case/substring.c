// **Count Substrings of a Given Length** - Write a function to count the number of substrings of a given length in a string.
// Example:
// Enter a string:i am khallikote 
// Enter substring length:3
// Number of substrings of length 3: 14

#include <stdio.h>
#include <string.h>

int countSubstrings(char str[], int length)
{
    int len = strlen(str);
    
    if(length > len || length <= 0)
    {
        return 0;
    }
    
    return len - length + 1;
}

int main()
{
    char str[100];
    int length;
    
    // User input 
    printf("Enter a string:");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline is present
    
    printf("Enter substring length:");
    scanf("%d", &length);
    
    // Count substrings of given length
    int count = countSubstrings(str, length);
    printf("Number of substrings of length %d: %d\n", length, count);
    
    return 0;
}