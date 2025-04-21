/*
Program: Multiply a number by 7 using bit manipulation
*/

#include <stdio.h>
int multiply (int x)
{
    return (x << 3) - x;
}

int main()
{
    int num = 9;
    printf("%d %d\n", num, multiply(num));
}