// Heap Sort algorithm
// Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure.

// A binary heap is a complete binary tree where the tree satisfies the "heap property":
// - Max Heap: The value of each parent node is greater than or equal to the values of its children.
// - Min Heap: The value of each parent node is smaller than or equal to the values of its children.

// The heap property ensures that the root node contains the largest (in a Max Heap) or smallest (in a Min Heap) element.

// **Heapifying**: 
// Heapify is a process where we ensure the heap property is maintained. If the parent node doesn't satisfy the heap property,
// it is adjusted (swapped with its larger/smaller child node) to ensure the heap structure is maintained.

// **Heap Sort Algorithm** involves the following key steps:

// 1. **Build a Max Heap** from the given input array:
//    - A Max Heap is built such that the largest element is at the root of the heap.
//    - We start heapifying from the non-leaf nodes, moving upwards toward the root, ensuring the heap property is maintained.

// 2. **Extract the Root** (the largest element in Max Heap):
//    - Once the Max Heap is built, the root contains the largest element.
//    - Swap the root element with the last element of the heap (this puts the largest element at the end of the array).
//    - After the swap, reduce the size of the heap by 1 and call heapify on the root to restore the heap property.
//    - The heap size is reduced each time, and the root is re-heapified to ensure the heap property is maintained.

// 3. **Repeat the Process** until the heap size is reduced to 1:
//    - Continue swapping the root with the last element, reducing the heap size, and heapifying the root.
//    - This process will eventually result in the array being sorted in ascending order.

// Heap Sort is an in-place sorting algorithm, meaning it doesn't require additional space to store the sorted elements.
// It guarantees O(n log n) time complexity for all cases (worst, average, and best), which makes it efficient for large datasets.
// However, the constant factors in Heap Sort might be higher than some other algorithms like Quick Sort, but Heap Sort is preferred when O(n log n) is a strict requirement.


#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int largest = i; // largest as root
    int left = 2 * i + 1; // left 
    int right = 2 * i + 2;

    // Check if the left chid exists and is greater than root
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Check if the right chid exists and is greater than root
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If largest is not root, swap and contiune heapified
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected
        heapify (arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    // Step 1: Build a Max Heap from the input array
    // A Max Heap is a binary tree where each parent node is greater than or equal to its children.
    // We start building the Max Heap from the last non-leaf node to the root.
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements one by one from the heap
    // Swap the root of the heap (largest element) with the last element of the heap
    // and reduce the size of the heap by 1.
    for (int i = n - 1; i > 0; i--) 
    {
        // Swap the root (largest) element with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call heapify on the reduced heap to restore the heap property
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr, n);

    printf("Sorted array is: \n");
    printArray(arr, n);

    return 0;
}
