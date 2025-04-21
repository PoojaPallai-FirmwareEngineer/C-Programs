// American Flag Sort Algorithm

/*
The **American Flag Sort** is a variation of the radix sort. The algorithm is named after the American flag because it divides the elements into multiple groups (or "buckets"), each representing different categories, just as the American flag has multiple colors and stripes.

## Steps:

1. **Input:**
   - The algorithm takes an array of numbers or items that need to be sorted.

2. **Determine the range of the elements:**
   - Identify the number of buckets based on the possible values in the input data.
   - Example: If the range of elements is from 0 to 255, create 256 buckets.

3. **Phase 1 - Grouping:**
   - Group the elements into different buckets based on a specific digit or key value.
   - Each bucket corresponds to a distinct part of the data (like a color or range).

4. **Phase 2 - Sorting within each bucket:**
   - Once the elements are grouped into buckets, sort the elements within each bucket.
   - This sorting can either be done recursively or using another sorting algorithm.

5. **Repeat for each digit or segment of the key:**
   - The sorting continues by focusing on each more significant part of the element (e.g., next digits or key parts).
   - This process is repeated until the entire set of elements is fully sorted.

## Example:

Consider the array `[4, 9, 3, 1, 8, 5, 6]`.

1. **Step 1**: Determine the range (1 to 9) and create 9 buckets.
2. **Step 2**: Sort the elements based on their value, placing them in the appropriate bucket.
3. **Step 3**: Sort the elements within each bucket if necessary.
4. **Step 4**: Repeat until the entire array is sorted.

## Use Cases:
- **Advantages**: The American Flag Sort is useful for sorting when there is a known and limited range of keys.
- **Disadvantages**: It is not as widely used as other sorting algorithms like quicksort and mergesort, especially for general-purpose sorting.
*/

#include <stdio.h>

void american_flag_sort(int arr[], int n, int max_value)
{
    // Step1: Initialize an array of buckets
    int buckets[max_value + 1]; // Create an array of size max_value + 1

    // Step 2: Initialize all buckets to 0
    for(int i = 0; i <= max_value; i++)
    {
        buckets[i] = 0;
    }

    // Step 3: Group the elements into buckets by counting their occurrences
    for(int i = 0; i < n; i++)
    {
        buckets[arr[i]]++;
    }

    // Step 4:Reconstruct the sorted array from the buckets
    int index = 0;
    for(int i = 0; i <= max_value; i++)
    {
        while (buckets[i] > 0)
        {
            arr[index++] = i;
            buckets[i]--;
        }
        
    }
}

int main() 
{
    int arr[] = {4, 9, 3, 1, 8, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_value = 9; // Max value in the array

    american_flag_sort(arr, n, max_value);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}


















