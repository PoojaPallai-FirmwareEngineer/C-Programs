// Ternary search 
// Ternary Search is a divide-and-conquer search algorithm that works on sorted arrays. It divides the search range into three parts 
// and determines which section may contain the target element. It then recursively searches in that section.

#include <stdio.h>

int ternarysearch(int arr[], int left, int right, int x)
{
    if (right >= left)
    {
        // Mid1 and Mid2
        int mid1 = left + (right - left) / 3;
        int mid2 = left + (right - left) / 3;

        // If x is at mid1 or mid2
        if (arr[mid1] == x)
        {
            return mid1;
        }

        if (arr[mid2] == x)
        {
            return mid2;
        }

        // determines which segment to search next
        if (x < arr[mid1])
        {
            // Search in the left segment
            return ternarysearch(arr, left, mid1 - 1, x);
        } else if (x > arr[mid2])
        {
            // Search in the right segment 
            return ternarysearch (arr, mid2 + 1, right, x);
        }
        else
        {
            return ternarysearch(arr, mid1 + 1, mid2 - 1, x);
        }
    }
    // Element not found
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 15; // Element to search

    int index = ternarysearch(arr, 0, n-1, x);

    if (index != -1)
    {
        printf("Element %d is found at index %d\n", x, index);
    }
    else
    {
        printf("Element %d is not found in the array \n", x);
    }
}