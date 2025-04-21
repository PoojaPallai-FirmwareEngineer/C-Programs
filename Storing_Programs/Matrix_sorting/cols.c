// Sort a 2D matrix column-wise

// Sort a 2D matrix row-wise

#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b)
{
    return(*(int *)a - *(int *)b);
}

void sortmartixcolumn(int matrix[][4], int rows, int cols)
{
    for (int col = 0; col < cols; col++)
    {
        // Create a temporary array to hold the column values
        int temp[rows];
        for(int row = 0; row < rows; row++)
        {
            temp[row] = matrix[row][col];
        }

        // Sort the column using qsort
        qsort(temp, rows, sizeof(int), compare);

        // Copy the sorted values back to the matrix column
        for (int row = 0; row < rows; row++) 
        {
            matrix[row][col] = temp[row];
        }
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
    sortmartixcolumn(matrix, rows, cols);

    printf("Sorted Matrix (column-wise):\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }

}