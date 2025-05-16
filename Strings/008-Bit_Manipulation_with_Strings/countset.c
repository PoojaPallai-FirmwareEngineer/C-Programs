// **Count Set Bits in a Binary String**- Write a function to count the number of set bits (1s) in a binary string.
// Example:
// Enter the string: 101010
// Number of sets:3

#include <stdio.h>
#include <string.h>

int binarystring(char *binstr)
{
    // Logic can be done 
    // 1. Using for loop with i index based
    // 2. Using for loop with i pointer 
    // 3. With while loop

    int count = 0;
    
    // Traverse through each character in the binary string until we hit the null character
    for(int i = 0; binstr[i] != '\0'; i++)
    {
        // Check if the current character is '1'
        if(binstr[i] == '1')
        {
            // Increment the count if it's a '1' (set bit)
            count++;
        }
    }
    return count;
}

int main()
{
    char binstr[100];
    printf("Enter the string: ");
    scanf("%s", binstr);
    
    int setbits = binarystring(binstr);
    
    printf("Number of sets:%d\n", setbits);
}
