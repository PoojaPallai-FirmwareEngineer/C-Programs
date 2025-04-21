/*
Program: Find the next power of 2 greater than or equal to a given number
*/

#include <stdio.h>
unsigned int powernext(unsigned int num)
{
    if (num == 0)
        return 1;
    
    num--;
    num |= num >> 1;
    num |= num >> 2;
    num |= num >> 4;
    num |= num >> 8;
    num |= num >> 16;

    return num + 1;
}

int main()
{
    int num = 9;
    printf("%d\n", powernext(num));
}