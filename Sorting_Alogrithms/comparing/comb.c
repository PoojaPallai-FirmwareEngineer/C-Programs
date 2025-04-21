/*
# **🔥 Comb Sort - An Optimized Bubble Sort 🔥**

Comb Sort is an **improved version of Bubble Sort**, designed to **eliminate small values (turtles) quickly** and improve sorting speed.  
It works by comparing elements with a **gap** that gradually shrinks to 1, making it more efficient than Bubble Sort.

---

## **📌 Why Comb Sort?**
✅ **Faster than Bubble Sort**: Reduces swaps by removing turtles early.  
✅ **Simple & Efficient**: Uses a shrinking gap for optimization.  
✅ **Easy to Implement**: No complex recursion or extra memory needed.  

---

## **🔹 How Comb Sort Works?**
### **1️⃣ Initialize Gap**
   - The **gap** is set as the array size (`n`).  
   - The gap is divided by **1.3** in each iteration (`gap = gap / 1.3`).  
   - The loop continues until the **gap becomes 1** (like Bubble Sort).  

### **2️⃣ Perform Comparisons & Swaps**
   - Compare elements at index `i` and `i + gap`.  
   - If **out of order**, swap them.  
   - Keep **shrinking the gap** until it's **1**, ensuring a final pass like Bubble Sort.

### **3️⃣ Final Pass with Gap = 1**
   - When the **gap reaches 1**, it functions like **Bubble Sort** but with fewer swaps.  
   - Ensures the array is fully sorted.

---

## **📊 Time Complexity**
| Case                             | Complexity                                |
|----------------------------------|-------------------------------------------|
| **Best Case** *(Already Sorted)* | **O(n log n)**                            |
| **Average Case**                 | **O(n² / 2^p)** (better than Bubble Sort) |
| **Worst Case**                   | **O(n²)**                                 |

- **Space Complexity**: **O(1)** (In-place sorting).  

---

## **✨ Key Advantages**
✔️ **Eliminates small values (turtles) early**  
✔️ **Faster than Bubble Sort for large datasets**  
✔️ **Easy to implement with no extra memory usage**  

🔹 **📌 In short, Comb Sort is an enhanced Bubble Sort that eliminates inefficiencies using a shrinking gap!** 🚀  
*/

#include <stdio.h>

int getNextGap(int gap)
{
    // Shrink gap by dividing by 1.3
    gap = (gap * 10) / 13;
    // Gap is atleast 1
    return (gap < 1) ? 1 : gap;
}

void combsort(int arr[], int n)
{
    int gap = n;
    int swapped = 1;

    while (gap != 1 || swapped)
    {
        gap = getNextGap(gap);
        swapped = 0;

        // Compare elements at index i and i+gap
        for (int i = 0; i < n - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                // Swap arr[i] and arr[i + gap]
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = 1;
            }
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

// Main function to test Comb Sort
int main() 
{
    int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    combsort(arr, n);

    printf("Sorted Array:\n");
    printArray(arr, n);

    return 0;
}