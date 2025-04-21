// **Merge two numbers by combining their bits using bitwise operations.**Hint**: Use shifts and masks to merge specific bit segments.

#include <stdio.h>

int mergeBitsOR(int a, int b)
{
    return a | b;
}

int interleaveBits(int a, int b)
{
    int result = 0;
    int maskA = 1, maskB = 1, pos = 0;

    while(a > 0 || b > 0)
    {
        // Extract LSB of A and place it in result
        if (a & maskA)
        {
            result |= (1 << (pos * 2)); // Move to the correct position
        }

        // Extract LSB of B and place it in result
        if (b & maskB)
        {
            result |= (1 << (pos * 2 + 1)); // Move to the correct position
        }

        // Shift A and B to get next bits
        a >>= 1;
        b >>= 1;
        pos++;
    }

    return result;
}

int main() 
{
    int A = 170;  // Binary: 10101010
    int B = 85;   // Binary: 01010101

    int mergedOR = mergeBitsOR(A, B);
    int mergedInterleave = interleaveBits(A, B);

    printf("A: %d (Binary: 10101010)\n", A);
    printf("B: %d (Binary: 01010101)\n", B);
    printf("Merged using OR: %d (Binary: 11111111)\n", mergedOR);
    printf("Merged by interleaving: %d (Binary: 11001100)\n", mergedInterleave);

    return 0;
}
