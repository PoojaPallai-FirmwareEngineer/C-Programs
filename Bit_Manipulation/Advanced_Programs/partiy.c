// Program to find the parity (even or odd number of 1s) of a number using bit manipulation in C
// - XOR all bits of the number.
// - If the result is 1, the parity is odd (odd number of 1s).
// - If the result is 0, the parity is even (even number of 1s).

#include <stdio.h>

int parity(int num)
{
    int parity = 0;

    while(num)
    {
        parity ^= (num & 1); // XOR the least significant bit
        num = num >> 1; // Right shift to move to the next bit
    }
    return parity;
}

int main()
{
    int num;
    printf("Enter the number:");
    scanf("%d", &num);

    if(parity(num))
    {
        printf("The number has an odd number of 1s in its binary representation.\n");
    }
    else 
    {
        printf("The number has an even number of 0s in its binary representation.\n");
    }
}

