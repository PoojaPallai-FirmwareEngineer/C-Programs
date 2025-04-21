// Calculate the logarithm base 2 of a number using bitwise operations

#include <stdio.h>

int logbase2(int num)
{
    if (num <= 0)
    {
        return -1; // logarithm undefined for non-positie numbers
    }

    int log = 0;
    while (num > 1)
    {
        num >>= 1; //Right shift the number by 1 (divide by 2)
        log++;
    }
    return log;
}

int main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int result = logbase2(num);

    if (result == -1) 
    {
        printf("Logarithm base 2 is undefined for %d.\n", num);
    } 
    else 
    {
        printf("The logarithm base 2 of %d is: %d\n", num, result);
    }

    return 0;
}