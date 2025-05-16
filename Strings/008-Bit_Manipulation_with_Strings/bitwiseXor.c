// **Bitwise XOR of Binary Strings** - Write a function to perform a bitwise XOR operation on two binary strings.
// Example
// Enter the binary string1:1101
// Enter the binary string1:1011
// the result is: 0110

#include <stdio.h>
#include <string.h>

void bitwisexor(char *bin1, char *bin2, char *result)
{
    // Logic can be done 
    // 1. Using for loop with i index based
    // 2. Using for loop with i pointer 
    // 3. With while loop

    int len = strlen(bin1);
    
    for(int i = 0; i < len; i++)
    {
        if(bin1[i] == bin2[i] )
        {
            result[i] = '0';
        }
        else
        {
            result[i] = '1';    
        }
        result[len] = '\0';
    }
}

int main()
{
    char bin1[200], bin2[200], result[200];
    
    printf("Enter the binary string1:");
    scanf("%s", bin1);
    
    printf("Enter the binary string1:");
    scanf("%s", bin2);
    
    // Check if lengths are equal
    if (strlen(bin1) != strlen(bin2)) 
    {
        printf("Error: Binary strings must have the same length.\n");
        return 1;
    }
    
    bitwisexor(bin1, bin2, result);
    
    printf("the result is: %s\n", result);
    
}

