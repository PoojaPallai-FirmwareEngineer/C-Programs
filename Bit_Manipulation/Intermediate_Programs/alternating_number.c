// Programs for Check if a number has alternating 0 and 1 bits (Binary Alternating Bits)
#include <stdio.h>
#include <stdbool.h>
bool alternating(int num)
{
    //Xor between n and n shifted right by 1 bit
    int xor = num ^ (num >> 1);

    // If xor + 1 is a power of 2 which means all the bits are 1
    return (xor & (xor + 1))== 0;
}

int main()
{
    int num;

    printf("Enter the num:");
    scanf("%u", &num);

    if (alternating(num))
    {
        printf("%d is a alternating bits\n", num);
    }
    else
    {
        printf("%d is not a alternating bits\n", num);
    }
}