// Write a function to reverse a string

#include <stdio.h>
#include <string.h>

void reverse_string(char *str)
{
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