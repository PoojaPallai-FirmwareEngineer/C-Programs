// **Bitwise OR of Binary Strings** - Write a function to perform a bitwise OR operation on two binary strings.
// Example
// Enter the binary string1:1011
// Enter the binary string1:1101
// the result is: 1111

#include <stdio.h>
#include <string.h>

void bitwiseor(char *bin1, char *bin2, char *result)
{
    // Logic can be done 
    // 1. Using for loop with i index based
    // 2. Using for loop with i pointer 
    // 3. With while loop

    int len = strlen(bin1);
    
    for(int i = 0; i < len; i++)
    {
        if(bin1[i] == '1' || bin2[i] == '1')
        {
            result[i] = '1';
        }
        else
        {
            result[i] = '0';    
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
    
    bitwiseor(bin1, bin2, result);
    
    printf("the result is: %s\n", result);
    
}

