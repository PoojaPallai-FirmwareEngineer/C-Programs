// ───────────────────────────────────────────────────────────────────
// 🌟 Shell Sort Algorithm - Optimized Insertion Sort 🌟
// ───────────────────────────────────────────────────────────────────

/*
   Shell Sort is an optimized version of Insertion Sort that works by sorting 
   elements far apart and progressively reducing the gap between them. 
   This helps move elements closer to their correct position faster, 
   reducing the number of swaps required compared to Insertion Sort.

   🔹 How It Works:
   1️⃣ Choose an initial gap (typically starting as half of the array size).
   2️⃣ Sort elements that are `gap` positions apart using insertion sort logic.
   3️⃣ Reduce the gap and repeat step 2.
   4️⃣ Continue until the gap becomes 1, at which point it behaves like Insertion Sort
      but with elements already closer to their sorted positions.
*/

#include <stdio.h>

void shellsort(int arr[], int n)
{
    // Start with a large gap and reduce at gradually
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Perform insertion sort for the current gap size
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;

            // Shift elements that are 'gap' apart to their correct position
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("🔹 Original Array:\n");
    printArray(arr, n);

    shellsort(arr, n); // Call the sorting function

    printf("✅ Sorted Array:\n");
    printArray(arr, n);

    return 0;
}