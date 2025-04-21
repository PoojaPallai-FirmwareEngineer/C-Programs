// Radix Sort

#include <stdio.h>
#include <stdlib.h>

int getMax(int arr[], int n)
{
    int max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void counting(int arr[], int n, int exp)
{
    int output[n]; // output array
    int count[10] = {0}; // Count array(for digits 0-9)
    
    // Step1: Count occurences of each element
    for(int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Step2: Compute prefix sum in count array
    for(int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Step5: Build the output array
    for(int i = n - 1; i >= 0; i--)
    {
        int digits = (arr[i] / exp) % 10;
        output[count[digits] - 1] = arr[i];
        count[digits]--;
    }

    // Step6: Copy sorted elements back to original array
    for(int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

}

void radixsort(int arr[], int n)
{
    int max = getMax(arr, n);

    for(int exp = 1; max / exp > 0; exp *= 10)
    {
        counting(arr, n, exp);
    }
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    radixsort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}