// Implement a function to swap all odd and even bits in an integer

#include <stdio.h>

unsigned int swapevenodd(int num)
{
    unsigned int oddMask = 0xAAAAAAAA;
    unsigned int evenMask = 0x55555555;

    // Extract the mask 
    unsigned oddbits = num & oddMask;
    unsigned evenbits = num & evenMask;

    // Shift odd bits to even positions and even bits to odd positions
    oddbits >>= 1;
    evenbits <<= 1;

    return (oddbits | evenbits);
}

int main()
{
    unsigned int num;

    printf("Enter a number: ");
    scanf("%u", &num);

    unsigned int result = swapevenodd(num);

    printf("Number after swapping odd and even bits: %u\n", result);

    return 0;
}