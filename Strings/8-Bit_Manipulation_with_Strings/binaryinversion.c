//**Binary String Inversion** - Write a function to invert a binary string (changing 0s to 1s and 1s to 0s).
// Example:
// Enter the string: 1110001
// The binary inversion is: 0001110

#include <stdio.h>
#include <string.h>

void binaryinversion(char *binstr)
{
    // Logic can be done 
    // 1. Using for loop with i index based
    // 2. Using for loop with i pointer 
    // 3. With while loop
    for(int i = 0; binstr[i] != '\0'; i++)
    {
        binstr[i] = (binstr[i] == '0') ? '1' : '0';
    }
}

int main()
{
    char binstr[100];
    printf("Enter the string: ");
    scanf("%s", binstr);
    
    binaryinversion(binstr);
    
    printf("The binary inversion is: %s\n", binstr);
}
