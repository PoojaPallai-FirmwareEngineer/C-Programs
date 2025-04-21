#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ASCENDING 1
#define DESCENDING 0

// Swap function
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bitonic Merge
void bitonicMerge(int arr[], int low, int count, int direction) 
{
    if (count > 1) {
        int k = count / 2;

        // Compare and swap
        #pragma omp parallel for
        for (int i = low; i < low + k; i++) 
        {
            if ((arr[i] > arr[i + k]) == direction) 
            {
                swap(&arr[i], &arr[i + k]);
            }
        }

        // Recursively merge the halves
        bitonicMerge(arr, low, k, direction);
        bitonicMerge(arr, low + k, k, direction);
    }
}

// Bitonic Sort
void bitonicSort(int arr[], int low, int count, int direction) 
{
    if (count > 1) 
    {
        int k = count / 2;

        // Recursively sort both halves in opposite directions
        bitonicSort(arr, low, k, ASCENDING);
        bitonicSort(arr, low + k, k, DESCENDING);

        // Merge the sorted sequence
        bitonicMerge(arr, low, count, direction);
    }
}

// Function to print the array
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int arr[] = {3, 7, 4, 8, 6, 2, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Ensure n is a power of 2
    if ((n & (n - 1)) != 0) 
    {
        printf("Array size must be a power of 2!\n");
        return 1;
    }

    printf("Original array: ");
    printArray(arr, n);

    // Parallel Bitonic Sort
    #pragma omp parallel
    {
        #pragma omp single
        bitonicSort(arr, 0, n, ASCENDING);
    }

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
