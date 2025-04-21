// Sort a 2D matrix row-wise

#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b)
{
    return(*(int *)a - *(int *)b);
}

void sortmartix(int matrix[][4], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        // Sort using qsort
        qsort(matrix[i], cols, sizeof(int), compare);
    }
}

int main()
{
    int matrix[3][4] =
    {
        {9, 2, 7, 4},
        {3, 8, 5, 1},
        {6, 0, 11, 10}
    };

    int rows = 3, cols = 4;

    printf("Original Matrix:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }

    // Sort the matrix row-wise
    sortmartix(matrix, rows, cols);

    printf("Sorted Matrix (row-wise):\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }

}