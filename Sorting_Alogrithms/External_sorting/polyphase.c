// Complier - gcc polyphase.c -Wall -Wextra -O2 -o polyphase

#include <stdio.h>
#include <stdlib.h>

#define MAX_RUNS 4 // Number of temporary runs
#define MAX_SIZE 100 // Maximum size of the array

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

void distributeRuns(int arr[], int n, int runs[MAX_RUNS][MAX_SIZE], int runsizes[MAX_SIZE])
{
    int runIndex = 0;
    int chunkSize = n / MAX_RUNS;

    for(int i = 0; i < MAX_RUNS; i++)
    {
        runsizes[i] = (i < MAX_RUNS - 1) ? chunkSize: (n - i * chunkSize);
        for(int j = 0; j < runsizes[i]; j++)
        {
            runs[i][j] = arr[runIndex++];
        }
        mergesort(runs[i], 0, runsizes[i] - 1); // sort each run
    }
}

void polyphaseMerge(int runs[MAX_RUNS][MAX_SIZE], int runsizes[MAX_RUNS], int output[], int totalSize)

{
    int indices[MAX_RUNS] = {0}; //Keep track of indices of each runs
    int outputIndex = 0;

    while(outputIndex < totalSize)
    {
        int minIndex = -1;
        int minValue = __INT_MAX__;

        // Find the minimum element among the runs
        for(int i = 0; i < MAX_RUNS; i++)
        {
            if(indices[i] < runsizes[i] && runs[i][indices[i]] < minValue)
            {
                minValue = runs[i][indices[i]];
                minIndex = i;
            }
        }

        // Add the smallest element to the final output
        if (minIndex != -1)
        {
            output[outputIndex++] = minValue;
            indices[minIndex]++;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to demonstrate Polyphase Merge Sort
int main() {
    int arr[] = {30, 10, 50, 20, 60, 40, 80, 70, 90, 100, 5, 15, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // Distribute runs
    int runs[MAX_RUNS][MAX_SIZE];
    int runSizes[MAX_RUNS] = {0};
    distributeRuns(arr, n, runs, runSizes);

    // Merge runs
    int output[MAX_SIZE];
    polyphaseMerge(runs, runSizes, output, n);

    printf("Sorted array: ");
    printArray(output, n);

    return 0;
}