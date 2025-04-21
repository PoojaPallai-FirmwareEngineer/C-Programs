// Interpolation search is an efficient search algorithm for finding a value in a sorted array.
// It works similarly to binary search, but instead of dividing the search range in half,
// it uses a mathematical formula to estimate the position of the key based on the value being searched for.

// How Interpolation Search Works:
// The idea is based on the assumption that values are uniformly distributed across the array.
// If the values are more densely packed in certain areas, this search algorithm can 
// potentially offer better performance than binary search.

// The formula used to estimate the position pos is:
// pos = low + ( (key - arr[low]) * (high - low) ) / (arr[high] - arr[low])

// Where:
// 'low' and 'high' are the indices of the current search range.
// 'arr[low]' and 'arr[high]' are the values at the low and high indices, respectively.
// 'key' is the value we are searching for.

// Steps Involved:
// 1. Start with the whole array: The search starts with the range from low = 0 to high = n-1, 
//    where n is the length of the array.
// 2. Calculate the probe position: Using the interpolation formula, calculate the position 'pos'
//    where the key might be located.
// 3. Compare the value at 'pos' with the key:
//    - If arr[pos] == key, we’ve found the key and return its position.
//    - If arr[pos] < key, the key is likely in the right half of the array, 
//      so update low = pos + 1 to narrow the search range to the right.
//    - If arr[pos] > key, the key is likely in the left half of the array, 
//      so update high = pos - 1 to narrow the search range to the left.
// 4. Repeat the process: Continue recalculating the probe position and adjusting the search 
//    range until the key is found or the search range is exhausted (i.e., low > high).

#include<stdio.h>
#include<stdio.h>
int interpolation_search(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    
    while(low <= high && target >= arr[low] && target <= arr[high])
    {
        int mid = low + ( (target - arr[low]) * (high - low) ) / (arr[high] - arr[low]);

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
    int target = 11;
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int result = interpolation_search(arr, size, target);

    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found at index");
    }
}
