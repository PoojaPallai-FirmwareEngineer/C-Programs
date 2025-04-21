#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 4  // Number of threads for parallel sorting

// Swap function for quicksort
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// QuickSort function for individual partitions
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];  
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);

        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Sample sort function
void sampleSort(int arr[], int n) {
    int numBuckets = NUM_THREADS;
    int pivots[NUM_THREADS - 1];  // Pivots for partitioning
    int *buckets[NUM_THREADS];    // Buckets to store partitions
    int bucketSize[NUM_THREADS] = {0}; // Initialize bucket sizes

    // Select pivot points: Choose evenly spaced elements as pivots
    for (int i = 0; i < numBuckets - 1; i++) {
        pivots[i] = arr[(i + 1) * (n / numBuckets)];
    }

    // Allocate memory for buckets
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int)); // Allocate memory for bucket
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < numBuckets - 1; j++) {
            if (arr[i] < pivots[j]) {
                buckets[j][bucketSize[j]++] = arr[i];
                break;
            }
        }
        if (j == numBuckets - 1) {
            buckets[numBuckets - 1][bucketSize[numBuckets - 1]++] = arr[i];
        }
    }

    // Sort each bucket in parallel
    #pragma omp parallel for num_threads(NUM_THREADS)
    for (int i = 0; i < numBuckets; i++) {
        if (bucketSize[i] > 0) { // Only sort if the bucket has elements
            quicksort(buckets[i], 0, bucketSize[i] - 1);
        }
    }

    // Merge sorted buckets back into the main array
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < bucketSize[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);  // Free allocated memory
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {30, 10, 20, 50, 40, 80, 60, 90, 70, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // Perform parallel Sample Sort
    sampleSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
