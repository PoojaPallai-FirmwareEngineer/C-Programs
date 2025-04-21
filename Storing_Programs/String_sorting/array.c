// Sort an array of strings alphabetically using strings 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparsion function to be used by qsort
int Comparsionstring(const void *a, const void *b)
{
    // Convert the void pointers to string pointers and compare them using strcmp
    return strcmp(*(const char **)a, *(const char **)b);
}

int main()
{
    // Arrays of strings 
    const char *arr[] = {"Banana", "Apple", "Orange", "Graphs", "Cherry"};
    int n = sizeof(arr)/ sizeof(arr[0]);

    // Sorting the array using qsort
    qsort(arr, n, sizeof(const char *), Comparsionstring);

    // Printing the sorted array
    printf("Sorted array of strings: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }
    return 0;
}