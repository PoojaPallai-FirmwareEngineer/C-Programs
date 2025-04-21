/*
Exponential Search is a combination of two algorithms:

1. Exponential Growth to find the range where the element may exist.
2. Binary Search to search within that range.

Key Points to Remember:
- Efficiency: Exponential search works well for sorted arrays and is effective when the search space is large.
- Logarithmic Time: It has a time complexity of O(log n), making it efficient for large datasets.
- Growth Phase: The algorithm increases the search range exponentially (i.e., powers of 2) until it finds a range where the target element might be.
- Binary Search: Once the range is found, binary search is applied within that range.
- Best Use Case: Suitable for searching large-sized arrays where binary search could be slow due to a large range.
- Precondition: The array must be sorted.

Steps:
1. Exponential Search Phase: Start with an index of 1, then double the index value (i.e., 2^0, 2^1, 2^2, ...) until you either go beyond the size of the array or find an index greater than or equal to the search element.
2. Binary Search Phase: After finding the appropriate range, apply binary search to locate the element.
*/

#include <stdio.h>

// Corrected Binary Search Function
int binary_search(int arr[], int low, int high, int target)
{
    // Loop until the range is valid (low <= high)
    while (low <= high)
    {
        int mid = (low + high) / 2; // Calculate mid point

        // Check if the target is at mid
        if (arr[mid] == target)
        {
            return mid; // Element found at index mid
        }
        // If target is smaller than mid, ignore the right half
        if (arr[mid] > target)
        {
            high = mid - 1;
        }
        // If target is larger than mid, ignore the left half
        else
        {
            low = mid + 1;
        }
    }
    return -1; // Target not found in array
}

// Exponential Search Function
int exponential_search(int arr[], int size, int target)
{
    // If the target is at the first position
    if (arr[0] == target)
    {
        return 0;
    }

    // Find the range for binary search by repeated doubling
    int i = 1;
    while (i < size && arr[i] <= target)
    {
        i *= 2;
    }

    // Perform binary search in the found range
    return binary_search(arr, i / 2, (i < size) ? i : size - 1, target);
}

int main()
{
    // Sorted array
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 15; // Element to search
    int size = sizeof(arr) / sizeof(arr[0]); // Size of the array

    // Call exponential search
    int result = exponential_search(arr, size, target);

    // Output the result
    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found in the array\n");
    }

    return 0;
}


