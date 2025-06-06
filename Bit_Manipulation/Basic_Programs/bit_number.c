// Program to bit manipulation
// 1. Set the i-th bit of a number
// 2. Clear the i-th bit of a number
// 3. Toggle_bit the i-th bit of a number
// 4. Check if the i-th bit is set
// 5. Turn off the rightmost set bit
// 6. Find the rightmost set bit of a number

#include<stdio.h>

int Set_bit(int num, int i)
{
    // To set the i-th bit, I use num | (1 << i). This ensures the i-th bit becomes 1, regardless of its previous value
    return num | (1 << i);
}

int clear_bit(int num, int i)
{
    // To clear the i-th bit, I use num & ~(1 << i). This forces the i-th bit to 0, while keeping all other bits unchanged.
    return num & ~(1 << i);
}

int toggle_bit(int num, int i)
{
    // To toggle the i-th bit, I use num ^ (1 << i). It flips the bit: 0 becomes 1, and 1 becomes 0.
    return num ^ (1 << i);
}

int check_bit(int num, int i)
{
    // To check if the i-th bit is set, I use (num & (1 << i)) != 0. If it's non-zero, the bit is set to 1.
    return (num & (1 << i)) != 0;
}

int turnoff_bit(int num, int i)
{
    // To turn off the rightmost 1-bit, I use num & (num - 1). It clears only the lowest set bit in the number.
    return num & (num - 1);
}

int rightmost_bit(int num, int i)
{
    // To find the rightmost 1-bit, I use num & -num. It isolates the lowest bit that is set to 1
    return num & -num;
}

int main()
{
    int num, i;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter the bit position to set: ");
    scanf("%d", &i);
    
    int result = Set_bit(num, i);
    printf("Result after setting the %d-th bit: %d\n", i, result);
    
    int result1 = clear_bit(num, i);
    printf("Result after clearing the %d-th bit: %d\n", i, result1);

    int result2 = toggle_bit(num, i);
    printf("Result after toggle the %d-th bit: %d\n", i, result2);

    int result3 = check_bit(num, i);
    printf("Result after checking the %d-th bit: %d\n", i, result3);

    int result4 = turnoff_bit(num, i);
    printf("Result after turn off over right most bit: %d\n", result4);

    int result5 = rightmost_bit(num, i);
    printf("Result after right bit to set the number: %d\n", result5);

    return 0;
}