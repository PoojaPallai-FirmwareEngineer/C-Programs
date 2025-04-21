/*
    Program: Find two non-repeating elements in an array where every other element repeats twice.
*/

#include <stdio.h>

void findNonRepeating(int arr[], int n, int *num1, int *num2)
{
    int result = 0;
    int i;

    // XOR for all elements
    for (i = 0; i < n; i++)
    {
        result ^= arr[i];
    }

    // Right most set bit
    int setbit = result & ~(result - 1);

    // Reset the numbers 
    *num1 = 0;
    *num2 = 0;

    // Divide elements into two groups and XOR within each group
    for (i = 0; i < n; i++)
    {
        if (arr[i] & setbit)
        {
            *num1 ^= arr[i];
        }
        else
        {
            *num2 ^= arr[i];
        }
    }
}

int main()
{
    int arr[] = {4, 5, 6, 7, 4, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int num1, num2;

    findNonRepeating(arr, n, &num1, &num2);

    printf(" The numbers are: %d %d\n", num1, num2);

    return 0;
}