// Sort characters in a single string alphabetically

#include <stdio.h>
#include <string.h>

void sortcharacters(char str[])
{
    int n = strlen(str); // Get the length of the string
    char temp;

    // Bubble Sort to sort the string characters
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            // Compare adjacent characters
            if (str[j] > str[j + 1]) 
            { 
                // Swap characters if out of order
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char str[100];

    // Input the string
    printf("Enter a string: ");
    scanf("%s", str);

    // Sort the string
    sortcharacters(str);

    // Print the sorted string
    printf("Sorted string: %s\n", str);

    return 0;
}