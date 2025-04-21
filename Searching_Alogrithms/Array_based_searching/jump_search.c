// Jump Search is a searching algorithm that works by dividing the search range 
// into smaller blocks and checking each block to see if the element is in that block.
// It is suitable for sorted arrays and improves over linear search by reducing 
// the number of comparisons made.
//
// The idea behind Jump Search is:
// 1. Jump ahead by a fixed block size (typically the square root of the total number 
//    of elements) and check if the target element lies in the current block.
// 2. If the target element is within the block, perform a linear search to find the exact element.

// Error found while executing: gcc jump_search.c -o jump_search
// /usr/bin/ld: /tmp/ccVNAzEX.o: in function `jumpsearch':
// jump_search.c:(.text+0x2a): undefined reference to `sqrt'
// /usr/bin/ld: jump_search.c:(.text+0x58): undefined reference to `sqrt'
// collect2: error: ld returned 1 exit status

// Solution: gcc jump_search.c -o jumpsearch -lm

#include<stdio.h>
#include<math.h>

int jumpsearch(int arr[], int n, int target)
{
    // Step 1: Determine block size
    // The block size is typically calculated as the square root of 
    // the number of elements,
    // i.e., block_size = sqrt(n).
    int block_size = (int)sqrt(n);
    int prev = 0;

    // Step 2: Jump through blocks
    // Start from the beginning and jump block_size elements at a time,
    // comparing the target with the last element in the block.
    while(arr[block_size - 1] < target && block_size < n)
    {
        prev = block_size;
        block_size += (int)sqrt(n); //Jump ahead by block_size
        if(block_size > n)
        {
            block_size = n; //Ensure block size doesn't exceed array length
        }
    }

    // Step 3: Linear search in the block
    // Once you identify the block in which the element may be located,
    // perform a linear search within that block.
    for(int i = 0; i < block_size; i++)
    {
        if(arr[i] == target)
        {
            return i; // Target found
        }
    }
    return -1;// Target not found
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; // Sorted array
    int target = 15;
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int result = jumpsearch(arr, size, target);

    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found at index");
    }
}
