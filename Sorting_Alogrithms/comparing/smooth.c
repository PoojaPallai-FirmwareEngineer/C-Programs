// Smooth sort Alogithm
// # Smoothsort - Theoretical Explanation

// <!-- 
// Smoothsort is a comparison-based sorting algorithm that improves upon Heapsort 
// by making it adaptive—meaning it runs in linear time (O(n)) when the input is nearly sorted. 
// It was invented by Edsger Dijkstra in 1981.
// -->

// ## Key Properties of Smoothsort
// <!-- 
// - **Adaptive:** Performs well on nearly sorted input (O(n)).
// - **In-place:** Does not require additional memory beyond the input array.
// - **Not stable:** It does not preserve the relative order of equal elements.
// - **Worst-case complexity:** O(n log n).
// -->

// ## How Smoothsort Works
// <!-- 
// 1. **Uses Leonardo Heaps**  
//    - Unlike Heapsort, which uses a binary heap, Smoothsort organizes elements using Leonardo heaps.
//    - Leonardo numbers follow the sequence: L(0) = 1, L(1) = 1, L(n) = L(n-1) + L(n-2) + 1.
//    - Example sequence: 1, 1, 3, 5, 9, 15, 25, 41, ...

// 2. **Heap Construction (Growing Phase)**  
//    - Elements are inserted while maintaining the Leonardo heap structure.
//    - Similar to a max-heap but using Leonardo tree properties.
//    - Ensures that larger values are at the top of the heaps.

// 3. **Heap Sorting (Shrinking Phase)**  
//    - The largest elements (heap roots) are extracted one by one.
//    - The heap is restructured after each extraction to maintain order.
//    - This results in a sorted array.
// -->

// ## Comparison with Other Sorting Algorithms
// <!-- 
// | Algorithm   | Best Case   | Worst Case  | Adaptive? | In-place? |
// |------------|------------|------------|-----------|-----------|
// | QuickSort  | O(n log n) | O(n²)      | No        | Yes       |
// | MergeSort  | O(n log n) | O(n log n) | No        | No        |
// | HeapSort   | O(n log n) | O(n log n) | No        | Yes       |
// | Smoothsort | O(n)       | O(n log n) | Yes       | Yes       |
// -->

// ## When to Use Smoothsort
// <!-- 
// - When the input is nearly sorted, achieving O(n) performance.
// - When an in-place sorting algorithm is required.
// - When a worst-case guarantee of O(n log n) is acceptable.
// -->

// ## When NOT to Use Smoothsort
// <!-- 
// - If a simple and faster alternative like Quicksort or Timsort works better for general cases.
// - If stability is required (Smoothsort is not stable).
// -->

#include <stdio.h>

#define LEO_MAX 46

void generate_leonardo(int leonardo[])
{
    leonardo[0] = 1;
    leonardo[1] = 2;
    for(int i = 2; i < LEO_MAX; i++)
    {
        leonardo[i] = leonardo[i - 1] + leonardo[i - 2] + 1;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shift_down(int arr[], int root, int size, int leonardo[], int order)
{
    while(order > 1)
    {
        int left = root - leonardo[order - 2] - 1;
        int right = root - 1;
        int larger = (arr[left] > arr[right]) ? left : right;

        if (arr[root] >= arr[larger]) break;

        swap(&arr[root], &arr[larger]);
        root = larger;
        order--;
    }
}

void Smoothsort(int arr[], int n)
{
    int leonardo[LEO_MAX];
    generate_leonardo(leonardo);

    int heap_size = 0, sizes[LEO_MAX], order = 0;

    // Growing phase (heap construction)
    for(int i = 0; i < n; i++)
    {
        if(order > 1 && sizes[order - 2] == sizes[order - 1] + 1)
        {
            sizes[order - 2]++;
            order--;
        }
        else
        {
            sizes[order++] = 1;
        }
    

        // Shift up 
        for (int j = order - 1, root = i; j > 0; j--)
        {
            int parent = root - leonardo[sizes[j] - 1];
            if (arr[root] > arr[parent])
            {
                swap(&arr[root], &arr[parent]);
                root = parent;
            }
            else
            {
                break;
            }
        }
    }

    // Shrinking pharse (heap sorting)
    for(int i = n - 1; i >= 0; i--)
    {
        if(sizes[order - 1] > 1)
        {
            int left = i - leonardo[sizes[order - 1] - 2];
            int right = i - 1;
            sizes[order] = sizes[order - 1] - 2;
            sizes[order - 1]--;
            order++;

            shift_down(arr, left, n, leonardo, sizes[order - 1]);
            shift_down(arr, right, n, leonardo, sizes[order - 1]);
        }
        else
        {
            order--;
        }
    }
}

int main() 
{
    int arr[] = {3, 7, 1, 9, 4, 6, 8, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    Smoothsort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}