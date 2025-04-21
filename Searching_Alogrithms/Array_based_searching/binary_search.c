// Definition
// Binary search is an efficient algorithm to find an element in a sorted array. 
// It repeatedly divides the search interval in half, eliminating half of the remaining elements after each comparison. 
// The time complexity of binary search is O(log n), making it much faster than linear search for large datasets.

// Binary Search Algorithm
// Step 1: Start with two pointers, low (pointing to the start of the array) and high (pointing to the end of the array).
// Step 2: Find the middle element (mid = (low + high) / 2).
// Step 3: Compare the middle element with the target value:
// If the middle element matches the target, the search is complete.
// If the middle element is greater than the target, eliminate the upper half of the search space by setting high = mid - 1.
// If the middle element is smaller than the target, eliminate the lower half by setting low = mid + 1.
// Step 4: Repeat the process until the target is found or low exceeds high, indicating the element is not present in the array.

#include<stdio.h>
int binary_search(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    
    while(low <= high)
    {
        int mid = (low + high)/ 2;

        // Check if target is at mid
        if (arr[mid] == target)
        {
            return mid;// Element found at index mid
        }
        
        if (arr[mid] > target)
        {
            high = mid - 1; // If target is smaller, ignore the right half
        }
        else
        {
            low = mid + 1; // If target is larger, ignore the left half
        }
    }
    return -1; // Target not found in array
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; // Sorted array
    int target = 15;
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int result = binary_search(arr, size, target);

    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found at index");
    }
}