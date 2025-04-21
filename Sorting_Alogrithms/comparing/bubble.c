// Bubble sort

#include <stdio.h>

void bubble(int arr[], int n)
{
    int temp, i, j;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+ 1] = temp;
            }
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
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printlist(arr, n);

    bubble(arr, n);

    printf("Sorted array: ");
    printlist(arr, n);
}