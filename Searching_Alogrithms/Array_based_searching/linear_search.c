// Concept for Linear search in C

// Definition
// Linear search is a straightforward algorithm that involves iterating through an array to find a specific element. 
// It checks each element one by one, and if the target element is found, it returns its index
// otherwise, it returns -1 after checking all elements.

// Diagram Explanation:
// Below is the step-by-step explanation of how the linear search algorithm works on the array {3, 5, 7, 9, 11} to 
// find the target 7.
// Initial Array:
// Index	0	1	2	3	4
// Value	3	5	7	9	11

// Step-by-Step Search Process:
// Step 1: Check the first element (index 0)
// Compare arr[0] = 3 with target = 7.
// 3 ≠ 7, so move to the next element.

// Step 2: Check the second element (index 1)
// Compare arr[1] = 5 with target = 7.
// 5 ≠ 7, so move to the next element.

// Step 3: Check the third element (index 2)
// Compare arr[2] = 7 with target = 7.
// 7 = 7, so the target is found at index 2.
// At this point, the search stops, and the function returns the index 2. 

// Time Complexity:
// 1. Best case: O(1) (if the target is the first element).
// 2. Worst case: O(n) (if the target is the last element or not present).
// 3. Average case: O(n), where n is the number of elements in the array.

// Space Complexity:
// 1. O(1): Constant space, as the search does not require extra memory apart from variables used for iteration.

// Advantages:
// 1. Simple to implement.
// 2. Can work on unsorted data.

// Disadvantages:
// 1. Inefficient for large datasets compared to other searching algorithms like binary search.

#include<stdio.h>
int linear_search(int arr[], int size, int target)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i; // Target found, return the index
        }
    }
    return -1; //Target not found
}

int main()
{
    int arr[] = {10, 20, 15, 25, 30, 45, 55};
    int target = 25;
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int result = linear_search(arr, size, target);

    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found at index");
    }
}

