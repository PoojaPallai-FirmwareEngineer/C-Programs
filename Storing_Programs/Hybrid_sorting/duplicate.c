// Sort an array with duplicate elements

// To sort an array with duplicate elements in C, you can use a sorting algorithm such as Bubble Sort, 
// Selection Sort, Insertion Sort, or even the qsort function from the C Standard Library for efficiency. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int arr[] = {4, 2, 5, 2, 8, 7, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");

    // Sorting the array using qsort
    qsort(arr, n, sizeof(int), Compare);

    // Printing the sorted array
    printf("Sorted array: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");

    return 0;
}