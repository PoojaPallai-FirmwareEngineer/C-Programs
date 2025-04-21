// **Implement a method to reverse only a portion of the bits within a number. **Hint**: Mask the portion, reverse it, and merge back.

#include <stdio.h>

unsigned int reversebitsinrange(unsigned int num, int start, int end)
{
    unsigned int mask = ((1U << (end - start + 1)) - 1) << start; // Create a mask for the range
    unsigned int portion = (num & mask) >> start; // extract the bits

    // Reverse the extracted bits
    unsigned int rev = 0;
    int size = end - start + 1;
    for (int i = 0; i < start; i++)
    {
        rev |= ((portion >> i) & 1) << (size - 1 - i);
    }

    num &= ~mask; // clear the original bit position
    num |= (rev << start); // merge the reversed bits back

    return num;
}

int main() 
{
    unsigned int num = 0b11011010;  // Example: 218 in decimal
    int start = 2, end = 5;  // Reverse bits from index 2 to 5

    printf("Original:  %u (Binary: %08X)\n", num, num);
    unsigned int result = reversebitsinrange(num, start, end);
    printf("Modified:  %u (Binary: %08X)\n", result, result);

    return 0;
}