// Program to find the largest power of two less than or equal to a given number
// - The technique clears all bits except the most significant bit.

#include <stdio.h>

int largestpower(int num)
{
    if (num <= 0)
    {
        return 0;
    }

    // // Keep setting all bits below the most significant bit
    num |= num >> 1;
    num |= num >> 2;
    num |= num >> 4;
    num |= num >> 6;
    num |= num >> 8;
    num |= num >> 16;

    return (num - (num >> 1));
}

int main()
{
    int num;
    printf("Enter the number:");
    scanf("%d", &num);

    // Find and display the largest power of two less than or equal to the number
    int result = largestpower(num);

    if (result > 0) 
    {
        printf("The largest power of two less than or equal to %d is: %d\n", num, result);
    } 
    else 
    {
        printf("No valid power of two exists for the input %d.\n", num);
    }
}