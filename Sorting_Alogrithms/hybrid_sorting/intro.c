// Complier - gcc -o intro intro.c -lm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void insertion(int arr[], int left, int right);
void Quick_Sort(int arr[], int low, int high, int depth_limit);
void heap_sort(int arr[], int n);
void swap(int *a, int *b);

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

void heap_sort(int arr[], int n)
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
        swap(&arr[0], &arr[i]);

        // Call heapify on the reduced heap to restore the heap property
        heapify(arr, i, 0);
    }
}

// Quick sort 
void Quick_Sort(int arr[], int low, int high, int depth_limit)
{
    while (high - low > 16)
    {
        // Use QuickSort if partition size > 16
        if (depth_limit == 0)
        {
            // If depth limit is reached, switch to heapsort
            heap_sort(arr + low, high - low + 1);
            return;
        }
        depth_limit--;

        int pivot = partition(arr, low, high);

        if(pivot - low < high - pivot)
        {
            QuickSort(arr, low, pivot - 1, depth_limit);
            low = pivot + 1;
        }
        else
        {
            QuickSort(arr, pivot + 1, high, depth_limit);
            high = pivot - 1;
        }
    }
}

// Insertion sort (used for small arrays)
void insertion(int arr[], int left, int right)
{
    for(int currentIndex = left + 1; currentIndex <= right; currentIndex++)
    {
        int currentValue = arr[currentIndex];
        int previousIndex = currentIndex - 1;

        // Move elements of arr[0..currentIndex-1] that are greater than currentValue
        // to one position ahead of their current position
        while (previousIndex >= left && arr[previousIndex] > currentValue)
        {
            arr[previousIndex + 1] = arr[previousIndex];
            previousIndex--;
        }
        // Insert the current value to current position
        arr[previousIndex + 1] = currentValue;
    }
}

void intro_sort(int arr[], int n)
{
    int depth_limit = 2 * log(n);
    QuickSort(arr, 0, n - 1, depth_limit);
    insertion(arr, 0, n - 1);
}

int main() 
{
    int arr[] = {10, 3, 8, 15, 6, 12, 2, 18, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    intro_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
