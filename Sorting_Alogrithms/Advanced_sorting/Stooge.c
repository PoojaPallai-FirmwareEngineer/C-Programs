#include <stdio.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Stoogesort(int arr[], int l, int h)
{
    if(arr[l] > arr[h])
    {
        swap(&arr[l], &arr[h]);
    }

    if (h - l + 1 > 2)
    {
        int t = (h - l + 1) / 3;

        // Sort first two-thirds
        Stoogesort(arr, l, h - t);
        // Sort last two-thirds
        Stoogesort(arr, l + t, h);
        // Sort first two-thirds again
        Stoogesort(arr, l, h - t);
    }
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {37, 23, 17, 89, 45, 78, 11, 67};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    Stoogesort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}