// Selection sort 

#include <stdio.h>

void selection(int arr[], int size)
{
    int temp, currentIndex, nextIndex;
    for(currentIndex = 0; currentIndex < size - 1; currentIndex++)
    {
        // The minimum elements in the remaining unsorted array
        int minIndex = currentIndex;
        for(nextIndex = currentIndex + 1; nextIndex < size; nextIndex++)
        {
            if (arr[nextIndex] < arr[minIndex])
            {
                minIndex = nextIndex;
            }
        }
        // Swap the found minimum elements with the first element of the unsorted array
        if (minIndex != currentIndex)
        {
            temp = arr[currentIndex];
            arr[currentIndex] = arr[minIndex];
            arr[minIndex] = temp;
        }
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

    selection(arr, size);

    printf("Sorted array: ");
    printlist(arr, size);
}