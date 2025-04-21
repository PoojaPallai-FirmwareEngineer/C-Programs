/*
 * Program to Find if Two Numbers Have Opposite Signs
 *
 * XOR is effective here because it directly operates on the binary representations of the numbers.
 * When two integers have opposite signs, the most significant bit (the sign bit in two's complement representation) 
 * will be different. By XORing the two numbers and checking the sign bit of the result, 
 * we can determine if they have opposite signs.
 *
 * Explanation of the XOR Approach:
 *
 * Two's Complement Representation:
 *   - In two's complement, the most significant bit (MSB) of an integer represents the sign:
 *       * 1 for negative numbers
 *       * 0 for positive numbers
 *
 * XOR Operation:
 *   - If num1 and num2 have opposite signs, their MSB (sign bit) will differ.
 *   - XORing these two numbers will set the sign bit of the result to 1, which makes the result a negative number.
 *   - If they have the same sign, the result of XOR will have the sign bit as 0, indicating a positive number or zero.
 *
 * Check the Sign of XOR Result:
 *   - By checking whether the result of the XOR operation is negative (< 0), 
 *     we can determine if the original numbers have opposite signs.
 *
 * Why is this efficient?
 *   - XOR directly compares the bits, which is a very fast operation at the hardware level.
 *   - It only requires one operation and a comparison, making it more efficient than approaches 
 *     that involve multiple logical comparisons.
 *
 * Summary:
 *   - The XOR approach is the correct and efficient bitwise method for determining if two numbers have opposite signs. 
 *   - It checks the most significant bit, where the sign of a number is stored in two's complement representation.
 */

#include<stdio.h>
int oppositesigns(int num1, int num2)
{
    return(num1 ^ num2) < 0;
}

int main()
{
    int num1 = -10, num2 = 20;

    if (oppositesigns(num1, num2))
    {
        printf("The numbers %d and %d have opposite signs.\n", num1, num2);
    } 
    else 
    {
        printf("The numbers %d and %d do not have opposite signs.\n", num1, num2);
    }
    return 0;
}

