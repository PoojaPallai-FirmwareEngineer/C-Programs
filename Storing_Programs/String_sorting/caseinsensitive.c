// Case-insensitive sorting of strings

// Case-insensitive sorting means comparing strings without considering the case of letters.
// For example, "Apple" and "apple" should be treated as equal during comparison.
// To implement case-insensitive sorting, you need:

// 1. A sorting algorithm (e.g., Bubble Sort, Quick Sort, etc.) to arrange the strings in order.
// 2. A comparison function that performs string comparison in a case-insensitive manner 
//    by converting characters to a uniform case (e.g., all lowercase or all uppercase) 
//    before comparison.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int caseinsensitivecompare(const char *a, const char *b)
{
    // Compare each character of the two strings
    while (*a && *b)
    {
        // Convert characters to lowercase using tolower for case-insensitive comparison
        char lowerA = tolower((unsigned char)*a);
        char lowerB = tolower((unsigned char)*b);

        // If characters are not equal return the difference 
        if (lowerA != lowerB)
        {
            return lowerA - lowerB;
        }
        a++;
        b++;
    }
    return *a - *b;
}

void caseinsensitive(char arr[][100], int n)
{
    char temp[100];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (caseinsensitivecompare(arr[i], arr[j]) > 0) 
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
    char arr[][100] = {"Banana", "apple", "Cherry", "date"};
    // Number of strings in the array
    int n = sizeof(arr) / sizeof(arr[0]); 

    // Sort the strings in case-insensitive order
    caseinsensitive(arr, n);

    // Print the sorted strings
    printf("Sorted strings (case-insensitive):\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}