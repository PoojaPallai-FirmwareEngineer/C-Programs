// Find the Hamming distance between two integers
#include <stdio.h>

int hammingdistance(int x, int y)
{
    int xor = x ^ y; // To find the differing bits
    int count = 0; // count the number of 1s in the xor result
    while (xor > 0)
    {
        count += xor & 1; // Increment count if the Lsb bit is 1
        xor >>= 1; // shift to right by 1 to check the next bit 
    }
    return count;
}

int main()
{
    int x = 5;
    int y = 6;

    int distance = hammingdistance(x, y);
    printf("Hamming Distance between %d and %d is: %d\n", x, y, distance);
}