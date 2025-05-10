// Reverse Bit Program
/*
The basic idea is to iterate through each bit of the integer, shift them into the correct position in the result
and reverse their order.

Step-by-step approach:
1. Initialize a variable to store the reversed bits.
2. Iterate through all the bits of the input integer:
   1. Shift the bits of the input integer to the right to access each bit.
   2. Shift the bits of the result to the left to make room for the new bit.
   3. Use bitwise OR to set the current bit of the result.
3. Return the reversed result.
*/

/*
These lines implement the core of the bit-reversal algorithm. Here's a detailed explanation:

1. reverseNum = (reverseNum << 1) | (num & 1);
   This line shifts the bits of reverseNum to the left and adds the least significant bit (LSB) of num to it.
   
   Let's break it down:

   reverseNum << 1:
   - Shifts all the bits of reverseNum one position to the left, similar to multiplying by 2 in binary.
   - For example, if reverseNum = 5 (binary 0101), shifting it left by 1 results in 1010 (binary), effectively doubling the value.
   - This shift creates space for a new bit at the rightmost position (least significant).

   num & 1:
   - This extracts the least significant bit (LSB) of num.
   - The bitwise AND operation (& 1) returns the LSB of num because 1 in binary is 0001. So, the result will be either 0 or 1, depending on whether the LSB of num is 0 or 1.
   - Example: If num = 12 (binary 1100), num & 1 gives 0 (since the LSB is 0).
   - If num = 13 (binary 1101), num & 1 gives 1 (since the LSB is 1).

   reverseNum = ... | (num & 1):
   - The bitwise OR (|) adds the extracted LSB of num to reverseNum.
   - Since reverseNum was already shifted left (creating room), the LSB of num is appended to the rightmost position of reverseNum.
   - Example: If reverseNum is 1010 and the LSB of num is 1, the result will be 1011.

2. num >>= 1;
   - This is a right shift operation, shifting all bits of num one position to the right.
   - The right shift discards the current LSB of num and brings the next bit into the LSB position.
   - This effectively divides num by 2 in binary.
   - Example: If num = 12 (binary 1100), after num >>= 1, it becomes 6 (binary 0110).

Combined effect of these two lines:
- The LSB of num is extracted and appended to reverseNum (by shifting reverseNum left and using OR).
- num is shifted to the right to prepare for the next bit in the next iteration.

Example Walkthrough for num = 12 in a 4-bit system:

Initial state:
   num = 1100 (decimal 12)
   reverseNum = 0000 (decimal 0)

Iteration breakdown:
  Iteration | num (binary) | num & 1 | reverseNum << 1 | reverseNum (new) | num >>= 1
  ------------------------------------------------------------------------------------
      1     |    1100      |    0    |      0000       |       0000       |    0110
      2     |    0110      |    0    |      0000       |       0000       |    0011
      3     |    0011      |    1    |      0000       |       0001       |    0001
      4     |    0001      |    1    |      0010       |       0011       |    0000

Final result:
   reverseNum = 0011 (binary), which is 3 in decimal.

NOTE: To remove the extra space use shift + tab
*/

#include <stdio.h>
unsigned int reverseBits(unsigned int num, int bitsize)
{
   unsigned int reverseNum = 0;
   int i;
   for(i = 0; i < bitsize; i++)
   {
      reverseNum = (reverseNum << 1) | (num & 1);
      num >>= 1;
   }
   return reverseNum;
}

int main()
{
   unsigned int num;
   int bitsize;

   printf("Enter the num:");
   scanf("%u", &num);
   printf("Enter the bit size (32, 16, 8 or 4):");
   scanf("%d", &bitsize);

   // Validate the bit size
   if (bitsize != 32 && bitsize != 16 && bitsize != 8 && bitsize != 4)
   {
      printf("Invalid bit size. Please enter 32, 16, 8, 4");
      return 1;
   }

   unsigned int result = reverseBits(num, bitsize);
   printf("Resversed bits of %u in %d bit size: %u\n", num, bitsize, result);

   return 0;

}
