// Write a function to reverse a string

#include <stdio.h>
#include <string.h>

void reverse_string(char *str)
{
    // logic can be done 
    // ✅ 1. Two-pointer approach (start and end) with while loop
    // ✅ 2. Two-pointer approach with for loop
    // ✅ 3. Using a single pointer (char *start, char *end) and swap
    // ✅ 4. Using recursion (swap first and last, move inward)
    // ✅ 5. Copy into a new array from end to start
    // ✅ 6. Using stack (push all characters, then pop)


    int start = 0;
    int end = 0;

    //Length of string
    while (str[end] != '\0')
    {
        end++;
    }
    end--;

    //Swap character from start to end
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}


int main()
{
    char str[100];
    printf("Enter the string:");
    // Read a string input
    fgets(str, sizeof(str), stdin);
    // Remove a newline character
    str[strcspn(str, "\n")] = 0;

    reverse_string(str);

    printf("Reverse string is %s\n", str);
}
