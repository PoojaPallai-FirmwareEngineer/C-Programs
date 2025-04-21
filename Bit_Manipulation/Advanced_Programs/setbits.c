// Find the number of bits needed to convert one number to another
// Find the minimum number of bit flips required to convert A to B

#include <stdio.h>

int countsetbit(int num)
{
    int count = 0;
    while (num > 0)
    {
        count += num & 1; // Check the least significant bit
        num = num >> 1;
    }
    return count;
}

int bitsToconvert(int a, int b)
{
    int xorResult = a ^ b;
    return countsetbit(xorResult);
}

int main()
{
    int a, b;

    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    // Calculate the number of bits needed to convert `a` to `b`
    int result = bitsToconvert(a, b);
    printf("The number of bits needed to convert %d to %d is: %d\n", a, b, result);

    return 0;
}