// Cocktail Shaker Sort algorithm 

// Cocktail Shaker Sort is a variation of Bubble Sort that sorts bidirectionally, 
// meaning it moves elements forward and backward in the list during each pass. 
// This helps to optimize the sorting process by reducing unnecessary comparisons.

// Algorithm:

// 1. Start with two boundaries: 'start' (beginning of the array) and 'end' (end of the array).
// 2. Traverse the array from left to right:
//    - Compare adjacent elements and swap them if needed, pushing the largest element to the end.
//    - After this pass, the largest element is correctly placed at the last position.
// 3. Decrease the 'end' boundary since the last element is in the correct position.
// 4. Traverse the array from right to left:
//    - Compare adjacent elements and swap them if needed, pushing the smallest element to the beginning.
//    - After this pass, the smallest element is correctly placed at the first position.
// 5. Increase the 'start' boundary since the first element is in the correct position.
// 6. Repeat steps 2-5 until no swaps are made in a full pass, indicating the array is sorted.

// Time Complexity:
// - Best Case (Already Sorted): O(n)
// - Worst Case (Reverse Sorted): O(n^2)
// - Average Case: O(n^2)

// Space Complexity: O(1) (in-place sorting)

// Cocktail Shaker Sort is more efficient than Bubble Sort for nearly sorted arrays but 
// remains inefficient for large datasets compared to algorithms like QuickSort and MergeSort.


#include <stdio.h>

void Cocktail(int arr[], int n)
{
    int swapped;
    int start = 0, end = n - 1;

    do 
    {
        swapped = 0;

        // Forward pass(left to right)
        for(int i = start; i < end; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                // swap elements
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped) break; // break if no swaps happened

        // Reduce end boundary
        end--;

        swapped = 0;

        // Backward pass(right to left)
        for(int i = end - 1; i >= start; i--)
        {
            if(arr[i] > arr[i + 1])
            {
                // swap elements
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        // Increase start boundary
        start++;
    }while(swapped);
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
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    Cocktail(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

