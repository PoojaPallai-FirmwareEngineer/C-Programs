// Sort a string array in descending order and aescending order

#include <stdio.h>
#include <string.h>

// Ascending order
void sortStringAscending(char arr[][100], int n)
{
    char temp[100];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0) 
            {
                // Swap strings if arr[i] > arr[j]
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        } 
    }
}

// Descending order
void sortStringDesscending(char arr[][100], int n)
{
    char temp[100];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[i], arr[j]) < 0) 
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
    int n;

    // Input the number of string 
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar(); // Consume the newline character after the integer input

    char arr[n][100];

    // Input the strings
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++)
    {
        fgets(arr[i], sizeof(arr[i]), stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0'; // Remove the trailing newline
    }

    // Sort the Ascending order
    sortStringAscending(arr, n);
    printf("\n Strings in Ascending order:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }

    // Sort the Descending order
    sortStringDesscending(arr, n);
    printf("\n Strings in Descending order:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }

    return 0;
}