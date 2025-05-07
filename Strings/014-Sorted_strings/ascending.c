// **Write a program to sort the characters in a string in ascending order.**
// Example:
// Enter the string:helloworld
// The sorted string is: dehllloorw

#include <stdio.h>
#include <string.h>

void sortstring(char str[])
{
    int len = strlen(str);
    char temp;
    
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0; j < len - i - 1; j++)
        {
            if(str[j] > str[j + 1])  // Ascending order
            // if(str[j] < str[j + 1]) // descending order
            {
                //swap character
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
    
    printf("Enter the string:");
    scanf("%s", str);
    
    sortstring(str);
    
    printf("The sorted string is: %s\n", str);
}