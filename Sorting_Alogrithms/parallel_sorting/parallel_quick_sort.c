#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_THRESOLD 1000 // Use threads only if the array ize is above this THREAD_THRESOLD

typedef struct 
{
    int *arr;
    int left;
    int right;
}sortparams;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int left, int right)
{
    int privot = arr[right]; // Choosing the last element as privot
    int i = left - 1; // Pointer to the smaller element

    for(int j = left; j < right; j++)
    {
        if (arr[j] < privot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

// Quick sort 
void QuickSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int pi = partition(arr, left, right); // Get privot index
        QuickSort(arr, left, pi - 1); // Sort left part
        QuickSort(arr, pi + 1, right); // Sort right part
    }
}

void *parallelQuicksort(void *arg)
{
    sortparams *params = (sortparams *)arg;
    int left = params->left;
    int right = params->right;
    int *arr = params->arr;

    if (left < right)
    {
        int pi = partition(arr, left, right);

        // Use threads only if the segment size is above the THREAD_THRESOLD
        if ((right - left) > THREAD_THRESOLD)
        {
            pthread_t leftThread, rightThread;
            sortparams leftParams = {arr, left, pi};
            sortparams rightParams = {arr, pi + 1, right};

            pthread_create(&leftThread, NULL, parallelQuicksort, &leftParams);
            pthread_create(&rightThread, NULL, parallelQuicksort, &rightParams);

            // Wait for both threads 
            pthread_join(leftThread, NULL);
            pthread_join(rightThread, NULL);
        }
        else
        {
            // Use sequential merge sort for small segments
            QuickSort(arr, left, pi);
            QuickSort(arr, pi + 1, right);
        }
    }
    return NULL;
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    sortparams params = {arr, 0, n - 1};
    pthread_t mainThread;

    // Start parallel merge sort
    pthread_create(&mainThread, NULL, parallelQuicksort, &params);
    pthread_join(mainThread, NULL);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
