// **Generate all possible subsets of a set using bitwise manipulation.**Hint**: Use the binary representation of numbers to represent subsets.

#include <stdio.h>

void generateSubsets(int arr[], int n) 
{
    int totalSubsets = 1 << n; // 2^n subsets

    printf("All Subsets:\n");
    for (int mask = 0; mask < totalSubsets; mask++) 
    {
        printf("{ ");
        for (int j = 0; j < n; j++) 
        {
            if (mask & (1 << j)) 
            {  // Check if j-th bit is set
                printf("%d ", arr[j]);
            }
        }
        printf("}\n");
    }
}

int main() 
{
    int arr[] = {1, 2, 3};  // Example set
    int n = sizeof(arr) / sizeof(arr[0]);

    generateSubsets(arr, n);

    return 0;
}