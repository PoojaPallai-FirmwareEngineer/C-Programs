/*
Program: Determine if a number is a palindrome in its binary form
*/

#include <stdio.h>
unsigned int reversedbit(unsigned int num)
{
    unsigned int reverse = 0;
    while(0 < num)
    {
        reverse = (reverse << 1) | (num & 1);
        num = num >> 1;
    }
    return reverse;
}

int ispalidrome(unsigned int num)
{
    unsigned int reversed = reversedbit(num);
    return num == reversed;
}

int main()
{
    unsigned int num = 9;
    printf("Binary representation is %u", num);
    for(int i = sizeof(num) * 8 - 1; i >= 0; i--)
    {
        printf("%d", (num << i) & 1);
    }
    printf("\n");

    if (ispalidrome(num))
    {
        printf("It is a palindrome:%u\n", num);
    }
    else
    {
        printf("It is not a palindrome:%u\n", num);
    }
}