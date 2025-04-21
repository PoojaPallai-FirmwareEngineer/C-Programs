// **Subtract two numbers using only bitwise operations.**Hint**: Use two’s complement and addition logic.

#include <stdio.h>

int bitwiseSubtract(int a, int b)
{
    while(b != 0)
    {
        int brrow = (~a & b);
        a = a ^ b;
        b = brrow << 1;
    }
    return a;
}

int main() 
{
    int x = 15, y = 7;
    printf("Subtracting %d - %d = %d\n", x, y, bitwiseSubtract(x, y));

    x = 25, y = 30;
    printf("Subtracting %d - %d = %d\n", x, y, bitwiseSubtract(x, y));

    return 0;
}