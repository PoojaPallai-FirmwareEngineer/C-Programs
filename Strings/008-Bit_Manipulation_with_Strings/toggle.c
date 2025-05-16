// **Toggle Case Using Bitwise Operations** - Write a function to toggle the case of all characters in a string using bitwise operations.
// Enter the string:acbfWGHT
// Toggled string is:ACBFwght


#include <stdio.h>

void toggle(char *str)
{
    // Logic can be done 
    // 1. Using for loop with i index based
    // 2. Using for loop with i pointer 
    // 3. With while loop
    
    while(*str)
    {
        if((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
        {
            *str = *str ^ 0x20; // ^ 0x20 efficiently toggles case
        }
        str++;
    }
}

int main()
{
    char str[100];
    printf("Enter the string:");
    scanf("%[^\n]", str);
    
    toggle(str);
    
    printf("Toggled string is:%s", str);
    return 0;
}