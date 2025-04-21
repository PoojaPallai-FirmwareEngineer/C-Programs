#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 4

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

// Merges two subarray of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m + 1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j]; 
    
    // Merge the temp arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[] if there any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[] if there any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void block_sort(int arr[], int n) {
    // Step 1: Sort each block using Insertion Sort
    for (int i = 0; i < n; i += BLOCK_SIZE) {
        int right = (i + BLOCK_SIZE - 1 < n) ? (i + BLOCK_SIZE - 1) : (n - 1);
        insertion(arr, i, right);
    }
    
    // Step 2: Merge sorted blocks
    for (int size = BLOCK_SIZE; size < n; size *= 2) {
        for (int left = 0; left < n - size; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n) ? (left + 2 * size - 1) : (n - 1);
            merge(arr, left, mid, right);
        }
    }
}

int main() {
    int arr[] = {12, 9, 7, 15, 10, 5, 3, 18, 6, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    block_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}