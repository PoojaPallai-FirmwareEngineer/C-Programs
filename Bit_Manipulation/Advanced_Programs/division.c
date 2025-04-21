/*
Program: Divide a number by 2 without using the division operator
*/

#include <stdio.h>
int division (int x)
{
    return (x >> 1);
}

int main()
{
    int num = 9;
    printf("%d %d\n", num, division(num));
}
