/*
    Patience Sorting

    Patience Sorting is a sorting algorithm inspired by the card game "Patience" (Solitaire).
    It is used in the Longest Increasing Subsequence (LIS) problem and has applications 
    in external sorting.

    -------------------------------------------------------
    Approach:
    -------------------------------------------------------
    1. Create Piles:
       - Each number from the input array is placed into the leftmost available pile 
         where it is greater than or equal to the top card.
       - If no such pile exists, a new pile is created.

    2. Merging the Piles:
       - The top cards of all piles form a Min-Heap.
       - The smallest card is removed and added to the sorted output.
       - The next card from the same pile is inserted back into the heap.
       - This process continues until all piles are empty.

    -------------------------------------------------------
    Efficient Implementation Using a Min-Heap:
    -------------------------------------------------------
    Why Use a Min-Heap?
    - A Min-Heap helps efficiently extract the smallest element from all the piles.
    - At each step, the smallest element is removed and replaced with the next element 
      from the same pile.
    - The heap maintains the order, ensuring efficient sorting.

    -------------------------------------------------------
    Time & Space Complexity:
    -------------------------------------------------------
    | Operation    | Complexity        |
    |-------------|------------------|
    | Creating piles | O(N log N)      |
    | Extracting elements | O(N log N) |
    | Overall Complexity | O(N log N)  |

    - Space Complexity: O(N) (for storing piles)

    -------------------------------------------------------
    Use Cases:
    -------------------------------------------------------
    - Longest Increasing Subsequence (LIS) problem
    - External Sorting (Sorting large files)
    - Merge operations in complex sorting problems

    -------------------------------------------------------
    Conclusion:
    -------------------------------------------------------
    - Patience Sort is useful for solving LIS problems and sorting efficiently.
    - It uses a pile-based approach with a Min-Heap for extraction.
    - The algorithm is not commonly used for general sorting but is valuable 
      in specialized scenarios.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in a linked list (for piles)
typedef struct Node 
{
    int value;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Piles function is the replica of binary_search few changes in name and mid
int FindPiles(Node* piles[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    
    while(low <= high)
    {
        int mid = (low + high)/ 2;
        
        if (piles[mid]->value >= target)
        {
            high = mid - 1; // If target is smaller, ignore the right half
        }
        else
        {
            low = mid + 1; // If target is larger, ignore the left half
        }
    }
    return low; // Target not found in array
}

// Patience sorted
void Patiencesort(int arr[], int n)
{
    Node* piles[n]; //Array of pile heads
    int pilecount = 0;

    // Step 1: Create piles
    for(int i = 0; i < n; i++)
    {
        int pileIndex = FindPiles(piles, pilecount, arr[i]);

        Node* newNode = createNode(arr[i]);
        if (pileIndex == pilecount)
        {
            // Create a new pile
            piles[pileIndex] = newNode;
            pilecount++; 
        }
        else
        {
            // Place the card on top of an existing pile
            newNode->next = piles[pileIndex];
            piles[pileIndex] = newNode;
        }
    }

    // Step2: Extract elements in sorted order
    for(int i = 0; i < n; i++)
    {
        int minPile = 0;
        for(int j = 1; j < pilecount; j++)
        {
            if(piles[j]->value < piles[minPile]->value)
                minPile = j;
        }

        arr[i] = piles[minPile]->value; // get the smallest value

        // Remove the top element from the selected pile
        Node* temp = piles[minPile];
        piles[minPile] = piles[minPile]->next;
        free(temp);

        // If the pile becomes empty, shift remaining piles
        if (!piles[minPile])
        {
            for(int j = minPile; j < pilecount - 1; j++)
            {
                piles[j] = piles[j + 1];
            }
            pilecount--;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main() {
    int arr[] = {3, 7, 2, 5, 1, 8, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    Patiencesort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

