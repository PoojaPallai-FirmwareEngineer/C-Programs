// Program to check if a number is a sparse number using bit manipulation in C
// A number is sparse if no two consecutive 1s are present in its binary representation.
// The condition can be checked using `num & (num >> 1)`:
// - If `num & (num >> 1)` is 0, the number is sparse.

#include <stdio.h>

int sparse(int num)
{
    return (num & (num >> 1)) == 0;
}

int main()
{
    int num;
    printf("Enter the number:");
    scanf("%d", &num);

    if(sparse(num))
    {
        printf("%d is a sparse number.\n", num);
    } 
    else 
    {
        printf("%d is not a sparse number.\n", num);
    }
}
