// Sort characters of a single string alphabetically
// To sort the characters of a single string alphabetically in C, 
// you can use a sorting algorithm such as Bubble Sort or Selection Sort to sort the individual characters of the string. 

#include <stdio.h>
#include <string.h>

void sortstring(char str[])
{
    int length = strlen(str);
    char temp;

    // Bubble sort to arrange characters alphabetically
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (str[i] > str[j])
            {
                // Swap characters
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main()
{
    char str[100];

    // Input string from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    //Remove newline characters from fgets
    str[strcspn(str, "\n")] = '\0';

    // Sort the string
    sortstring(str);

    printf("Sorted string: %s\n", str);
}