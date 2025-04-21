// Count the number of trailing zeros in a binary number

#include <stdio.h>
int countTrailingzeros(int num)
{
    if(num == 0)
    {
        return -1; // special case for 0 as it has no set bits
    }

    int count = 0;
    while ((num & 1) == 0) // check if the least significant bit is 0
    {
        count++;
        num >>= 1; // Right shift to check the next bit
    }
    return count;
}

int main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int result = countTrailingzeros(num);
    
    if (result == -1) 
    {
        printf("The number is 0 and has no set bits.\n");
    } 
    else 
    {
        printf("The number of trailing zeros in %d is: %d\n", num, result);
    }

    return 0;
}
