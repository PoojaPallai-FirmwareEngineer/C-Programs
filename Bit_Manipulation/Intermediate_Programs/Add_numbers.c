/*
Program for Add two numbers without using arithmetic operators
The key idea is to repeatedly calculate the sum of the bits and the carry generated during the addition. 
Here's how you can do it:
Steps:
1. Use the XOR (^) operator to sum the bits without considering the carry.
2. Use the AND (&) operator to calculate the carry.
3. Shift the carry left by one bit (<<) since the carry affects the next higher bit.
4. Repeat the process until there is no carry left.

Explanation:
1. XOR (^) gives the sum of a and b without carrying.
2. AND (&) gives the carry bits, which are shifted left (<<) to add at the higher bit positions.
3. This process continues until there is no carry left (i.e., b == 0).
*/

#include <stdio.h>
int add(int a, int b)
{
    while (b != 0)
    {
        //calculate carry
        int carry = a & b;

        // calculate sum without carry
        a = a ^ b;

        // Shift carry left by 1 to add in the next bit position 
        b = carry << 1; 
    }
    return a;
}

int main()
{
    int num1 = 15, num2 = 25;
    printf("Sum of %d and %d is: %d\n", num1, num2, add(num1, num2));
    return 0;
}
