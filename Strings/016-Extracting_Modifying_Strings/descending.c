// **Extract digits from a string and sort them in descending order.**
// Example:
// Enter a string: hello123world456
// Sorted digits in descending order: 654321

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN    100

int extractdigits(char *str, int digits[])
{
    int count = 0;
    
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            digits[count++] = str[i] - '0'; // convert char to int
        }
    }
    return count;
}

void sortdescending(int digits[MAX_LEN], int count)
{
    int temp;
    
    for( int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - i - 1; j++)
        {
            if(digits[j] < digits[j + 1])
            {
                temp = digits[j];
                digits[j] = digits[j + 1];
                digits[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char str[MAX_LEN];
    int digits[MAX_LEN], count;

    // Input string from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Extract digits
    count = extractdigits(str, digits);

    if (count == 0) 
    {
        printf("No digits found in the string.\n");
    } 
    else 
    {
        // Sort digits in descending order
        sortdescending(digits, count);

        // Print sorted digits
        printf("Sorted digits in descending order: ");
        for (int i = 0; i < count; i++) 
        {
            printf("%d", digits[i]);
        }
        printf("\n");
    }

    return 0;
}
