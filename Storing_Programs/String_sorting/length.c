// Sort strings by length

#include <stdio.h>
#include <string.h>

void sortlength(char arr[][100], int n)
{
    char temp[100];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strlen(arr[i]) > strlen(arr[j]))  
            {
                // Swap strings if arr[i] < arr[j]
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        } 
    }
}

int main() 
{
    // Array of strings to be sorted
    char arr[][100] = {"Banana", "apple", "Cherry", "date", "Hi"};
    // Number of strings in the array
    int n = sizeof(arr) / sizeof(arr[0]); 

    // Sort the strings in case-insensitive order
    sortlength(arr, n);

    // Print the sorted strings
    printf("Sorted strings by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}