/*
Program: Find the number that appears only once in an array where every other element appears three times. 
    **Hint**: Track counts of bits at every position.
*/

#include <stdio.h>
int findsinglelement(int arr[], int n)
{
    int ones = 0;
    int twos = 0; 
    int common_bits_mask, i;

    for(i = 0; i < n; i++)
    {
        twos = twos | (ones & arr[i]);
        ones = ones ^ arr[i];
        common_bits_mask = ~(ones & twos);
        ones = ones & common_bits_mask;
        twos = twos & common_bits_mask;    
    }
    return ones;
}

int main()
{
    int arr[] = {3, 3, 2, 3};
    int n = sizeof(arr)/ sizeof(arr[0]);
    printf("the ones element is :%d\n", findsinglelement(arr, n));
    return 0;
}