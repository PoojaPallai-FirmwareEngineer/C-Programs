#include <stdio.h>

int binary_search(int arr[], int low, int high, int target)
{    
    while(low <= high)
    {
        int mid = low + (high - low)/ 2;

        // Check if target is at mid
        if (arr[mid] == target)
        {
            return mid + 1; // Insert after duplicates
        }
        
        else if (arr[mid] > target)
        {
            high = mid - 1; 
        }
        else
        {
            low = mid + 1; 
        }
    }
    return low; 
}

void binaryInsertionsort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int pos = binary_search(arr, 0, i - 1, key);

        // Shift elements to make space for the key
        int j = i;
        while(j > pos)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[pos] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {37, 23, 17, 89, 45, 78, 11, 67};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    binaryInsertionsort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}