// Gnome Sort Algorithm

// Gnome Sort is a simple sorting algorithm that works similarly to Insertion Sort 
// but swaps adjacent elements if they are out of order, moving backward when necessary. 
// It is sometimes called the "Stupid Sort" due to its naive approach.

// Algorithm:

// 1. Start at the first index (index = 0).
// 2. Compare the current element with the previous element:
//    - If they are in order, move forward (index++).
//    - If they are out of order, swap them and move one step back (index--).
// 3. Repeat until the array is sorted (i.e., when index == size).

// Time Complexity:
// - Best Case (Already Sorted): O(n)
// - Worst Case (Reverse Sorted): O(n^2)
// - Average Case: O(n^2)

// Space Complexity: O(1) (in-place sorting)

// Gnome Sort is useful for nearly sorted arrays but inefficient for large datasets 
// compared to algorithms like QuickSort or MergeSort.


#include <stdio.h>

void gnome(int arr[], int n)
{
    int index = 0;

    while(index < n)
    {
        if(index == 0 || arr[index] >= arr[index - 1])
        {
            // Move forward if elements are in order
            index++;
        }
        else
        {
            int temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;

            // Move backward
            index--;
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


int main() 
{
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    gnome(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}