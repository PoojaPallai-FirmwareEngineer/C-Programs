// Convert a decimal number to binary without using a built-in method
#include <stdio.h>

void decimaltoBinary(int decimal)
{
    int binary[32];
    int index = 0; // Index to fill the binary array

    while (decimal > 0)
    {
        binary[index] = decimal % 2; // Store the remainder
        decimal = decimal / 2; // Update the decimal number
        index++;
    }

    // Print the binary number in reverse order
    printf("Binary representation: ");
    for(int i = index - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main()
{
    int decimal;
    printf("Enter the decimal number: ");
    scanf("%d", &decimal);

    if (decimal == 0)
    {
        printf("Binary representation: 0\n");
    }
    else
    {
        decimaltoBinary(decimal);
    }
}