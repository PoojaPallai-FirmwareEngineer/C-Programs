/*
Program: Implement a bitwise AND of numbers in a given range `[m, n]`
*/

#include <stdio.h>
int bitwiseand(int m,int n)
{
    while (m < n)
    {
        n = n & (n - 1);
    }
    return n;
}

int main()
{
    int n = 7, m = 5;
    printf("%d %d %d\n", m, n, bitwiseand(m, n));
}