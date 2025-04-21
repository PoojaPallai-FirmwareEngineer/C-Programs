// Sort integers with negative and positive numbers

#include <stdio.h>

void sortIntegers(int arr[], int n) 
{
    int temp;

    // Bubble Sort algorithm
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[100], n;

    printf("Enter the number of integers: \n");
    scanf("%d", &n);

    // Input the positive array
    printf("Enter %d integers (both positive and negative allowed):\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    sortIntegers(arr, n);

    // Print the sorted array
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}