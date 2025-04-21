#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 1000 // Maximum array sizeof
#define THREAD_THRESOLD 1000 // Use threads only if the array ize is above this THREAD_THRESOLD

typedef struct 
{
    int *arr;
    int left;
    int right;
}sortparams;

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

void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Parallel merge sort (used by threads)
void *parallelMergesort(void *arg)
{
    sortparams *params = (sortparams *)arg;
    int left = params->left;
    int right = params->right;
    int *arr = params->arr;

    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Use threads only if the segment size is above the THREAD_THRESOLD
        if ((right - left) > THREAD_THRESOLD)
        {
            pthread_t leftThread, rightThread;
            sortparams leftParams = {arr, left, mid};
            sortparams rightParams = {arr, mid + 1, right};

            pthread_create(&leftThread, NULL, parallelMergesort, &leftParams);
            pthread_create(&rightThread, NULL, parallelMergesort, &rightParams);

            // Wait for both threads 
            pthread_join(leftThread, NULL);
            pthread_join(rightThread, NULL);
        }
        else
        {
            // Use sequential merge sort for small segments
            mergesort(arr, left, mid);
            mergesort(arr, mid + 1, right);
        }

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
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
    pthread_create(&mainThread, NULL, parallelMergesort, &params);
    pthread_join(mainThread, NULL);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}