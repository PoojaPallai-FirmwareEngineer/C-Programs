// **Rotate bits of a number to the left or right.**Hint**: Use shifts and `|` to wrap bits around.

#include <stdio.h>
#define INT_BITS 32 

// Rotate bits to the left
unsigned int rotateLeft(unsigned int num, int bits)
{
    return (num << bits) | (num >> (INT_BITS - bits));
}

// Rotate bits to the right
unsigned int rotateRight(unsigned int num, int bits)
{
    return (num >> bits) | (num << (INT_BITS - bits));
}

int main()
{
    unsigned int num = 0b10110011; // 179 in decimal
    int rotateby = 3;

    printf("Original:       %u(binary: %08X)\n", num, num);
    printf("Left Rotate:    %u (Binary: %08X)\n", rotateLeft(num, rotateby), rotateLeft(num, rotateby));
    printf("Right Rotate:   %u (Binary: %08X)\n", rotateRight(num, rotateby), rotateRight(num, rotateby));
}







