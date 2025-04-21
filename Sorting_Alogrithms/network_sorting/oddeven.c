#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void oddevensort(int arr[], int n)
{
    bool sorted = false; // flag to check if array is sorted

    while (!sorted)
    {
        sorted = true;

        // odd phase: compare elements at odd indices
        for (int i = 1; i < n - 1; i += 2)
        {
            if (arr[i] > arr[i + 1])
            {
            swap(&arr[i], &arr[i + 1]);
            sorted = false;  
            }
        }

        // even phase: compare elements at even indices
        for (int i = 0; i < n - 1; i += 2)
        {
            if (arr[i] > arr[i + 1])
            {
            swap(&arr[i], &arr[i + 1]);
            sorted = false;  
            }
        }
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

// Main function
int main() 
{
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    // Sorting using Odd-Even Sort
    oddevensort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}