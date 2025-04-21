// Find the closest integer with the same number of 1s in binary representation.**Hint**: Swap the lowest set bit and the rightmost unset bit.

#include <stdio.h>
#include <stdlib.h>

// Swap the lowest set bit with the righmost unset bit
unsigned int closestSamebitcount(unsigned int n)
{
    if (n == 0 || n == ~ 0)
    {
        printf("No valid closest number exists\n");
        return n;
    }

    for(int i = 0; i < 31; i++)
    {
        if (((n >> i) & 1) != ((n >> i + 1) & 1))
        {
            n ^= (1 << i) | (1 << ( i + 1));
            return n;
        }
    }
    return n; // should never reach here
}

int main() 
{
    unsigned int num = 6;  // Binary: 00000110
    printf("Original: %u (Binary: 00000110)\n", num);
    
    unsigned int result = closestSamebitcount(num);
    printf("Closest: %u (Binary: %08X)\n", result, result);

    return 0;
}