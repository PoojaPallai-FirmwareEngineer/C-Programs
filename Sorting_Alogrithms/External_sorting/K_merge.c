/*
    K-Way Merge Sort

    K-Way Merge Sort is an efficient algorithm used to merge multiple sorted arrays 
    (or partitions) into a single sorted array. This algorithm is particularly useful 
    for external sorting, where the dataset is too large to fit into memory.

    -------------------------------------------------------
    Approach:
    -------------------------------------------------------
    1. Divide the Data into K Sorted Subarrays:
       - The input data is divided into 'K' sorted partitions.
       - These partitions may have been sorted earlier (e.g., in an external sorting process).

    2. Merge the Sorted Subarrays Efficiently:
       - A Min-Heap (Priority Queue) is used to efficiently extract the smallest element 
         from the 'K' arrays.
       - Alternatively, a merge function can be used to merge two arrays at a time.

    3. Continue Merging Until a Single Sorted Array is Obtained:
       - The smallest element is repeatedly extracted from the Min-Heap and placed in 
         the final output array.
       - The merging process continues until all subarrays are merged into one 
         fully sorted array.

    -------------------------------------------------------
    Efficient Implementation Using a Min-Heap:
    -------------------------------------------------------
    Why Use a Min-Heap?
    - A Min-Heap helps efficiently extract the smallest element from 'K' sorted lists.
    - At each step, the smallest element is removed from the heap and replaced with 
      the next element from the same subarray.
    - The heap restructures itself (heapify) to maintain its properties.

    Heap Operations:
    1. Insertion – Adding the first element from each sorted array.
    2. Extraction – Removing the smallest element and adding the next element from 
       the same array.
    3. Heapify – Restoring the heap property after each operation.

    -------------------------------------------------------
    Time & Space Complexity:
    -------------------------------------------------------
    | Operation   | Complexity          |
    |------------|---------------------|
    | Inserting K elements in the heap | O(K)           |
    | Extracting elements (K × N times)| O(KN log K)    |
    | Overall Complexity               | O(KN log K)    |

    - Space Complexity: O(K) (for storing K elements in the heap)

    -------------------------------------------------------
    Use Cases:
    -------------------------------------------------------
    - External Sorting (Sorting large files that don’t fit in RAM)
    - Merging Sorted Log Files (e.g., combining sorted transaction logs)
    - Database Query Processing (Merging multiple sorted query results)
    - Streaming Data Processing (Handling continuous sorted data streams)

    -------------------------------------------------------
    Conclusion:
    -------------------------------------------------------
    - K-Way Merge Sort is an optimal approach for merging multiple sorted arrays efficiently.
    - The Min-Heap (Priority Queue) method ensures that merging occurs in O(KN log K) time.
    - It is widely used in external sorting algorithms to handle massive datasets 
      that exceed memory limits.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define K 3 // Number of sorted arrays
#define N 4 // Number of elements per array

typedef struct 
{
    int value;
    int arrayIndex;
    int nextIndex;
}HeapNode;

void swap(HeapNode *x, HeapNode *y)
{
    HeapNode temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(HeapNode heap[], int size, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && heap[left].value < heap[smallest].value)
    {
        smallest = left;
    }

    if(right< size && heap[right].value < heap[smallest].value)
    {
        smallest = right;
    }

    if(smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void buildMinHeap(HeapNode heap[], int size)
{
    for(int i = (size - 1) / 2; i >= 0; i--)
    {
        minHeapify(heap, size, i);
    }
}

void KwayMerge(int arr[K][N], int output[K * N])
{
    HeapNode heap[K]; // Min-heap of K elements

    // Initalize help with first element of each array
    for(int i = 0; i < K; i++)
    {
        heap[i].value = arr[i][0];
        heap[i].arrayIndex = i;
        heap[i].nextIndex = 1;
    }

    // Build the heap
    buildMinHeap(heap, K);

    // Merge process
    for(int i = 0; i < K * N; i++)
    {
        // extractt the smallest element
        output[i] = heap[0].value;

        // Find next element from the same array
        int arrayIdx = heap[0].arrayIndex;
        int nextIdx = heap[0].nextIndex;

        if(nextIdx < N)
        {
            heap[0].value = arr[arrayIdx][nextIdx];
            heap[0].nextIndex++;
        } 
        else
        {
            heap[0].value = INT_MAX; // Mark as infinity if no more elements
        }

        // Heapify to maintain min-heap property
        minHeapify(heap, K, 0);
    }
}

int main() 
{
    int arr[K][N] = 
    {
        {1, 5, 9, 13},
        {2, 6, 10, 14},
        {3, 7, 11, 15}
    };

    int output[K * N];
    
    KwayMerge(arr, output);

    // Print the merged sorted array
    printf("Merged Sorted Array: ");
    for (int i = 0; i < K * N; i++) 
    {
        printf("%d ", output[i]);
    }
    printf("\n");

    return 0;
}












