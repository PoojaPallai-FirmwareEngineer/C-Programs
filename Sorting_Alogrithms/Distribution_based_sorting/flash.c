#include <stdio.h>
#include <stdlib.h>

#define ALPHA 0.43 // Tuning factor for classification step

void flashsort(int arr[], int n)
{
    int min = arr[0], max = arr[0];

    // Step 1: Find min and max
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    if (min == max) return; // Already sorted

    // Step 2: Create L (Classification) array
    int m = (int)(ALPHA * n);
    if (m < 2) m = 2; // Ensure at least two classes

    int *L = (int *)calloc(m, sizeof(int)); // Allocate memory for L
    if (!L) 
    {
        printf("Memory allocation failed\n");
        return;
    }

    // Step 3: Count elements per class
    for (int i = 0; i < n; i++)
    {
        int k = (m - 1) * (arr[i] - min) / (max - min);
        if (k < 0) k = 0;
        if (k >= m) k = m - 1;
        L[k]++;
    }

    // Step 4: Convert L to position indices
    for (int i = 1; i < m; i++)
    {
        L[i] += L[i - 1];
    }

    // Step 5: Permutation step (placing elements in correct class)
    int count = 0, i = 0;
    while (count < n)
    {
        int k = (m - 1) * (arr[i] - min) / (max - min);

        // Avoid overwriting elements in their positions
        while (i >= L[k])
        {
            i++;
            if (i >= n) break;
            k = (m - 1) * (arr[i] - min) / (max - min);
        }

        if (i >= n) break;

        int temp = arr[i];

        // Swap elements into their correct classes
        while (i != L[k])
        {
            int pos = --L[k];
            int temp2 = arr[pos];
            arr[pos] = temp;
            temp = temp2;
            k = (m - 1) * (temp - min) / (max - min);
            if (k < 0) k = 0;
            if (k >= m) k = m - 1;
            count++;
        }
    }

    free(L); // Free allocated memory

    // Step 6: Final insertion sort
    for (int currentIndex = 1; currentIndex < n; currentIndex++)
    {
        int currentValue = arr[currentIndex];
        int previousIndex = currentIndex - 1;

        while (previousIndex >= 0 && arr[previousIndex] > currentValue)
        {
            arr[previousIndex + 1] = arr[previousIndex];
            previousIndex--;
        }

        arr[previousIndex + 1] = currentValue;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // Don't use 5 since it will come duplicate of it.
    int arr[] = {3, 2, 8, 1, 9, 6, 7, 4, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    flashsort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
