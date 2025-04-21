// Bucket sort 

#include <stdio.h>
#include <stdlib.h>

void insertion(float arr[], int size)
{
    for(int currentIndex = 1; currentIndex < size; currentIndex++)
    {
        float currentValue = arr[currentIndex];
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

void bucketsort(float arr[], int n)
{
    // Step1: Create n empty buckets
    int bucketCount = n;
    float **buckets = (float **)malloc(bucketCount * sizeof(float *));
    int *bucketsize = (int *)calloc(bucketCount, sizeof(int));

    for(int i = 0; i < bucketCount; i++)
    {
        buckets[i] = (float *)malloc(n * sizeof(float));
    }

    // Step2: Place array elements into different buckets
    for(int i = 0; i < n; i++)
    {
        int bucketIndex = n * arr[i]; // Index in bucket
        buckets[bucketIndex][bucketsize[bucketIndex]++] = arr[i];
    }

    // Step3: Sort each bucket using insertion sort
    for(int i = 0; i < bucketCount; i++)
    {
        if(bucketsize[i] > 0)
        {
            insertion(buckets[i], bucketsize[i]);
        }
    }

    // Step4: Concatenate all sorted buckets into the original array
    int index = 0;
    for(int i = 0; i < bucketCount; i++)
    {
        for(int j = 0; j < bucketsize[i]; j++)
        {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]); 
    }

    free(buckets);
    free(bucketsize);
}

void printArray(float arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}


int main() 
{
    float arr[] = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bucketsort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}