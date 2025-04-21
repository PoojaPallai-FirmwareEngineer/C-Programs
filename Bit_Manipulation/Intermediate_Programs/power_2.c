#include <stdio.h>
int poweroftwo(int num)
{
    if(num <= 0)
    {
        return 0; // Not the power of 2
    }
    return (num & (num - 1)) == 0;
}

int main()
{
    int num;

    printf("Enter the num:");
    scanf("%u", &num);

    if (poweroftwo(num))
    {
        printf("%d is a power of two.\n", num);
    }
    else
    {
        printf("%d is not a power of two.\n", num);
    }

    return 0;
}
    
