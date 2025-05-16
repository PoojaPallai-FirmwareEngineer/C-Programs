// **String Permutations:** Write a function to find all permutations of a string.
// Example: 
// All permutations of "ABC":
// ABC
// ACB
// BAC
// BCA
// CBA
// CAB

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *str, int left, int right)
{
    if(left == right)
    {
        printf("%s\n", str);
        return;
    }
    
    for(int i = left; i <= right; i++)
    {
        swap(&str[left], &str[i]);
        permute(str, left + 1, right);
        swap(&str[left], &str[i]);
    }
}

int main() 
{
    char str[] = "ABC";  // Input string
    int n = strlen(str);
    
    printf("All permutations of \"%s\":\n", str);
    permute(str, 0, n - 1);  // Generate permutations
    
    return 0;
}
