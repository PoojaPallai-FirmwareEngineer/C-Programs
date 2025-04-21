// Sort a jagged array row-wise

// Sorting a jagged array row-wise in C requires handling the fact that the rows in the array may have different lengths. 
// A jagged array can be implemented in C using a pointer to an array of pointers, where each pointer represents a row.

#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b)
{
    return(*(int *)a - *(int *)b);
}

void sortjagged(int **jaggedArray, int rowsize[], int rows)
{
    for(int i = 0; i < rows; i++)
    {
        qsort(jaggedArray[i], rowsize[i], sizeof(int), compare);
    }
}

int main() 
{
    // Define a jagged array
    int row1[] = {3, 1, 4};
    int row2[] = {9, 7};
    int row3[] = {5, 2, 8, 6};

    // Array of pointers to rows
    int *jaggedArray[] = {row1, row2, row3};

    // Array containing the sizes of each row
    int rowSizes[] = {3, 2, 4};  // Number of elements in each row
    int rows = 3;  // Number of rows in the jagged array

    // Print the original jagged array
    printf("Original Jagged Array:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < rowSizes[i]; j++) 
        {
            printf("%5d", jaggedArray[i][j]);
        }
        printf("\n");
    }

    // Sort the jagged array row-wise
    sortjagged(jaggedArray, rowSizes, rows);

    // Print the sorted jagged array
    printf("\nSorted Jagged Array (row-wise):\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < rowSizes[i]; j++) 
        {
            printf("%5d", jaggedArray[i][j]);
        }
        printf("\n");
    }

    return 0;
}