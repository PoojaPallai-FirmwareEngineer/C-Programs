// **Binary String to Integer** - Write a function to convert a binary string into an integer.
// Enter the string:1101
// The decimal integer:13


#include <stdio.h>

int binarytointeger(char *binary)
{
    int result = 0;
    
    // Logic can be done 
    // 1. Using for loop with i index based
    // 2. Using for loop with i pointer 
    // 3. With while loop
    while(*binary)
    {
        result = result * 2 + (*binary - '0'); // convert char to integer
        binary++;
    }
    return result;
}

int main()
{
    char binarystr[100];
    printf("Enter the string:");
    scanf("%s", binarystr);
    
    int decimal_integer = binarytointeger(binarystr);
    printf("The decimal integer:%d\n", decimal_integer);
    
    return 0;
}