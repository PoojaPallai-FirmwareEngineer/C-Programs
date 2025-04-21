// Sort an array with unique elements only

// To sort an array with only unique elements in C, you can use a sorting algorithm or the qsort function.
//  However, if the array initially contains duplicate elements, you need to remove the duplicates before sorting.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// To remove the duplicates in the array
int removeduplicates(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    // Index for next unique element 
    int uniqueIndex = 0;

    for(int i = 1; i < n; i++)
    {
        if (arr[i] != arr[uniqueIndex])
        {
            uniqueIndex++;
            arr[uniqueIndex] = arr[i];
        }
    }

    return uniqueIndex + 1; // New size of the array
}

int main ()
{
    int arr[] = {4, 2, 5, 2, 8, 7, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Step 1: Sort the array
    qsort(arr, n, sizeof(int), Compare);

    // Step 2: Remove duplicates
    n = removeduplicates(arr, n);

    printf("Array with unique elements (sorted): ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}