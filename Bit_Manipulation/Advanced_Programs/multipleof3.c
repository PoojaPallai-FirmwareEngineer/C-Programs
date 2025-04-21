// Program to check if a number is a multiple of 3 using bit manipulation in C
// This program uses the property of binary representation and the difference between 
// the count of 1s at odd and even positions in the binary form of the number.
// If the difference is divisible by 3, the number is also divisible by 3.

#include <stdio.h>
int multipleofthree(int num)
{
    int oddcount = 0;
    int evencount = 0;

    // Handle negative numbers by taking the absolute value
    if (num < 0)
    {
        num = -num;
    }

    // Loop through all bits of the number
    while(num)
    {
        if(num & 1) // Check the least significant bit
        {
            oddcount++; // Increment odd position count
        }
        num = num >> 1; // Right shift to move to the next bit

        if(num & 1) // Check the least significant bit
        {
            evencount++; // Increment even position count
        }
        num = num >> 1; // Right shift to move to the next bit
    }
    // The difference and check divisibility by 3
    return(oddcount - evencount) % 3 == 0;
}

int main()
{
    int num;
    printf("Enter the number:");
    scanf("%d", &num);

    if(multipleofthree(num))
    {
        printf("%d is a multiple by 3\n", num);
    }
    else
    {
        printf("%d is not a multiple by 3\n", num);
    }

}