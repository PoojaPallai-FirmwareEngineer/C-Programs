// Sort an array of characters (e.g., A-Z or a-z)
// To sort an array of characters (e.g., A-Z or a-z) in C, 
// you can use a simple sorting algorithm such as Bubble Sort or Quick Sort.

#include <stdio.h>
#include <string.h>

void sortcharacters(char arr[], int n)
{
    char temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        } 
    }
}

int main() 
{
    // Array of characters to be sorted
    char arr[] = {'D', 'A', 'C', 'B', 'E'};
    // Number of strings in the array
    int n = sizeof(arr) / sizeof(arr[0]); 

    // Sort the strings in case-insensitive order
    sortcharacters(arr, n);

    // Print the sorted strings
    printf("Sorted characters:\n");
    for (int i = 0; i < n; i++) {
        printf("%c\n", arr[i]);
    }

    return 0;
}