// Quick Sort Algorithm  
// Reference: https://www.geeksforgeeks.org/quick-sort-in-c/  

/*  
QuickSort is a popular sorting algorithm that follows the **Divide and Conquer** paradigm.  
It works by selecting a **pivot** element, partitioning the array into two subarrays  
(elements less than and greater than the pivot), and then recursively sorting the subarrays.  
*/

/*  
### QuickSort Algorithm Steps:  
1. **Choose a pivot** (typically the first, last, middle, or a random element).  
2. **Partition the array**:  
   - Rearrange elements such that elements smaller than the pivot go to its left  
     and larger ones go to its right.  
3. **Recursively apply QuickSort** to the left and right subarrays.  
4. **Base case**: Stop when the subarray has one or zero elements (already sorted).  
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high)
{
    int privot = arr[high]; // Choosing the last element as privot
    int i = low - 1; // Pointer to the smaller element

    for(int j = low; j < high; j++)
    {
        if (arr[j] < privot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick sort 
void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high); // Get privot index
        QuickSort(arr, low, pi - 1); // Sort left part
        QuickSort(arr, pi + 1, high); // Sort right part
    }
}

void printarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t ", arr[i]);
        printf("\n");
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printarray(arr, n);
    
    QuickSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    printarray(arr, n);
    
    return 0;
}

