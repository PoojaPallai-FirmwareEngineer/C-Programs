/*
# **🏆 Tim Sort - Hybrid Sorting Algorithm 🏆**

Tim Sort is a **hybrid sorting algorithm** that combines the advantages of **Merge Sort** and **Insertion Sort**.  
It is designed to work efficiently on **real-world data**, especially when the data is **partially sorted**.  
Tim Sort is the default sorting algorithm in:  
✔️ **Python's `sort()` function**  
✔️ **Java’s `Arrays.sort()` method for objects**  

---

## **📌 Why Tim Sort?**
✅ **Faster for real-world data**: Works well with nearly sorted data.  
✅ **Adaptive**: Uses **Insertion Sort** for small segments and **Merge Sort** for larger ones.  
✅ **Stable Sorting Algorithm**: Preserves the order of equal elements, which is crucial for sorting records.  

---

## **🔹 How Tim Sort Works?**
### **1️⃣ Divide the Array into Small Chunks (Runs)**
   - The array is split into small **sorted subarrays (runs)** of size `RUN` (typically **32 or 64**).  
   - **Insertion Sort** is applied to efficiently sort each individual run.

### **2️⃣ Merge Runs Using Merge Sort**
   - After sorting small chunks, adjacent runs are **merged** using an **optimized Merge Sort**.  
   - The merging process ensures efficiency and minimizes unnecessary comparisons.

### **3️⃣ Final Sorted Array**
   - The process continues until the **entire array** is merged into a fully sorted list.  

---

## **📊 Time Complexity**
| Case                               | Complexity     |
|------------------------------------|----------------|
| 🔹 **Best Case** *(Nearly Sorted)* | **O(n)**       |
| 🔹 **Average Case**                | **O(n log n)** |
| 🔹 **Worst Case**                  | **O(n log n)** |

- **Space Complexity**: **O(n)** (Uses extra space for merging).
---
## **✨ Key Advantages**
✔️ **Faster for partially sorted data**  
✔️ **More efficient than traditional Merge Sort in practice**  
✔️ **Widely used in modern programming languages** (Python, Java, etc.)  

*/

#include <stdio.h>
#include <stdlib.h>

#define RUN 32

void insertionsort(int arr[], int left, int right)
{
    for(int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int len1 = mid - left + 1;
    int len2 = right - mid;

    int *leftarr = (int *)malloc(len1 * sizeof(int));
    int *rightarr = (int *)malloc(len2 * sizeof(int));

    // Copy data to temporary Arrays
    for (int i = 0; i < len1; i++) leftarr[i] = arr[left + i];
    for (int i = 0; i < len2; i++) rightarr[i] = arr[mid + 1 + i];

    // Merge back to original array
    int i = 0, j = 0, k = left;
    while (i < len1 && j < len2)
    {
        if (leftarr[i] <= rightarr[j])
        {
            arr[k++] = leftarr[i++];
        }
        else
        {
            arr[k++] = rightarr[j++];
        }
    }

    // Copy remaining elements
    while (i < len1) arr[k++] = leftarr[i++];
    while (j < len2) arr[k++] = rightarr[j++];

    free(leftarr);
    free(rightarr);
}

void timsort(int arr[], int n)
{
    // Step 1: Sort small segments using Insertion sort
    for(int i = 0; i < n; i+= RUN)
    {
        insertionsort(arr, i, (i + RUN - 1 < n - 1) ? (i + RUN - 1): (n - 1));
    }

    // Step 2: Merge the sorted runs
    for (int size = RUN; size < n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ? (left + 2 * size - 1) : (n - 1);

            if (mid < right)
            {
                merge(arr, left, mid, right);
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() 
{
    int arr[] = {5, 21, 7, 23, 19, 3, 8, 1, 6, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("🔹 Original Array:\n");
    printArray(arr, n);

    timsort(arr, n);

    printf("✅ Sorted Array:\n");
    printArray(arr, n);

    return 0;
}



















