// Program for Count the number of set bits in an integer (Hamming Weight)
// Approach are 
// 1. Bitwise operations
// 2. Hamming weight 

#include <stdio.h>
int UsingBitwiseOperation(int num)
{
    int count = 0;
    while (num != 0)
    {
        // Check the last bit of 1
        if (num & 1)
        {
            count++;
        }
        num >>= 1;
    }
    return count;
}

int hammingweight(int num)
{
    int count = 0;
    while (num != 0)
    {
        // Check the lowest set the bit
        num = (num & num - 1);
        count++;
    }
    return count;
}

int main()
{
    int num = 13;

    printf("Hamming Weight using bitwise operation of %u is: %d\n", num, UsingBitwiseOperation(num));
    printf("Hamming Weight of %u is: %d\n", num, hammingweight(num));

    return 0;
}