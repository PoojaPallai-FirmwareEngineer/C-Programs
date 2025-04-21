#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bitonicMerge(int arr[], int low, int count, int dir)
{
    if (count > 1)
    {
        int k = count / 2;
        for (int i = low; i < low + k; i++)
        {
            if((dir == 1 && arr[i] > arr[i + k]) || (dir == 0 && arr[i] < arr[i + k]))
            {
                swap(&arr[i], &arr[i + k]);
            }
        }
        bitonicMerge(arr, low, k, dir);
        bitonicMerge(arr, low + k, k, dir);
    }
}

void bitonicSort(int arr[], int low, int count, int dir)
{
    if (count > 1)
    {
        int k = count / 2;

        // Sort the 1st half in ascending order
        bitonicSort(arr, low, k, 1);

        // Sort the 2nd half in ascending order
        bitonicSort(arr, low + k, k, 0);

        // Merge the entire sequence 
        bitonicMerge(arr, low, count, dir);
    }
}

// Wrapper function for bitonic Sort
void sort(int arr[], int n, int up)
{
    bitonicSort(arr, 0, n, up);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {3, 7, 4, 8, 6, 2, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    // Sorting in ascending order (up=1)
    sort(arr, n, 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}