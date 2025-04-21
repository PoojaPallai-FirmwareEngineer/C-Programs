// Program to check if a number is divisible by 4 using bit manipulation in C
// The last two bits of a number determine divisibility by 4:
// If the last two bits are `00`, the number is divisible by 4.

#include <stdio.h>
int multipleoffour(int num)
{
    // Check if the last two bits are 0 using bitwise AND
    return (num & 3) == 0;
}

int main()
{
    int num;
    printf("Enter the number:");
    scanf("%d", &num);

    if(multipleoffour(num))
    {
        printf("%d is a multiple by 4\n", num);
    }
    else
    {
        printf("%d is not a multiple by 4\n", num);
    }

}