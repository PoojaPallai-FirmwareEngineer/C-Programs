// Counting sort 

#include <stdio.h>
#include <stdlib.h>

void counting(int arr[], int n)
{
    // Step1: Find the maximum values
    int max = arr[0];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i]; 
    }

    // Step2: Create and initalize the count array
    int *count = (int  *)calloc(max + 1, sizeof(int));

    // Step3: Count occurences of each element
    for(int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Step4: Compute prefix sum in count array
    for(int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // Step5: Build the output array
    int *output = (int *)malloc(n * sizeof(int));
    for(int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step6: Copy sorted elements back to original array
    for(int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    free(count);
    free(output);
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
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    counting(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}