/*
 * Program: Find the Only Non-Repeating Element in an Array
 * Goal: Identify the single element in the array that appears exactly once,
 *       while all other elements appear twice.
 *
 * How It Works:
 * - The XOR operation is used to cancel out repeating elements.
 * - XOR Properties:
 *   1. a ^ a = 0 (Any number XORed with itself is 0)
 *   2. a ^ 0 = a (Any number XORed with 0 remains unchanged)
 * - By XORing all elements in the array:
 *   - Repeating pairs cancel each other out (result in 0).
 *   - The non-repeating element remains as the final result.
 *
 * Example:
 * Input:  {2, 3, 7, 3, 2}
 * Output: 7
 * Explanation: 7 is the only element that does not repeat.
 */

#include <stdio.h>

int nonrepeating(int arr[], int n)
{
    int result = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        result ^= arr[i];
    }
    return result;
}

int main()
{

    int arr[] = {2, 3, 7, 3, 2};
    int n = sizeof(arr)/ sizeof(arr[0]);

    int single_element = nonrepeating(arr, n);
    printf("The unique element: %d\n", single_element);

    return 0;
}
