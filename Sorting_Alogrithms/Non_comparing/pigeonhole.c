// Pigeonhole Sort 

#include <stdio.h>
#include <stdlib.h>

void pigeonhole(int arr[], int n)
{
    int min = arr[0], max = arr[0];

    // find the range (min and max values)
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < min)
            min = arr[i];
        if(arr[i] > max)
            max = arr[i];
    }

    int range = max - min + 1; // No.of pigeonhole needed
    int* pigeonhole = (int *)calloc(range, sizeof(int));

    // Populate pigeonhole
    for(int i = 0; i < n; i++)
    {
        pigeonhole[arr[i] - min]++;
    }

    // Reconstruct the sorted array
    int index = 0;
    for(int i = 0; i < range; i++)
    {
        while (pigeonhole[i]-- > 0)
        {
            arr[index++] = i + min;
        }
    }

    free(pigeonhole); // Free allocated memory
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    int arr[] = {8, 3, 2, 7, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    pigeonhole(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}