#include <stdio.h>

void insertion(int arr[], int size)
{
    for(int currentIndex = 1; currentIndex < size; currentIndex++)
    {
        int currentValue = arr[currentIndex];
        int previousIndex = currentIndex - 1;

        // Move elements of arr[0..currentIndex-1] that are greater than currentValue
        // to one position ahead of their current position
        while (previousIndex >= 0 && arr[previousIndex] > currentValue)
        {
            arr[previousIndex + 1] = arr[previousIndex];
            previousIndex--;
        }
        // Insert the current value to current position
        arr[previousIndex + 1] = currentValue;
    }
}

void printlist(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {64, 33, 25, 13, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printlist(arr, size);

    insertion(arr, size);

    printf("Sorted array: ");
    printlist(arr, size);
}