/*
Program for Find the position of the most significant set bit
The most significant set bit in a binary representation of a number, we aim to locate the position of the leftmost 1. 
Here's how it can be done:
Steps:
    1. Binary Representation: Convert the number into its binary form.
    2. Position Indexing: Positions in binary representation are generally counted from right to left (starting at 0). The most significant bit (MSB) is the leftmost 1 bit.
    3. Method: To find the position of the most significant set bit in an integer, we can use several methods:
        ◦ Logarithmic Method: The position of the most significant set bit is related to the number of bits required to represent the number, which is essentially the floor value of the logarithm base 2 of the number.
        ◦ Bit Manipulation: We can shift the number right until the only bit left is the most significant one.
Execution step: gcc most_significant_bit.c -o most_significant_bit -lm
*/
#include <stdio.h>
#include <math.h>
int Findmsb(int num)
{
    int pos = -1;
    while(num > 0)
    {
        num = num >> 1;
        pos++;
    }
    return pos;
}

int findmsblog(int num)
{
    if (num == 0)
    {
        return -1; // No set bit to 0
    }
    // Returns the position of the MSB (0-indexed)
    return (int)log2(num);
}

int main()
{
    int num = 20;
    int result = Findmsb(num);
    int result1 = findmsblog(num);
    printf("The most significant set bit is at position: %d\n", result);
    printf("The most significant set bit is at position: %d\n", result1);
}
