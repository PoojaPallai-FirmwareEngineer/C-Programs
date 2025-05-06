// **Check if Two Strings Are Equal After Removing All Occurrences of a Character** - Write a function that checks if two strings are equal after removing all occurrences of a character.
// Example:
// Enter first string: hello world
// Enter second string: hello
// Enter character to remove: 1
// The strings are NOT equal after removing '1'.

#include <stdio.h>
#include <string.h>

void removecharacter(char *str, char ch)
{
    int i, j = 0;
    int length = strlen(str);
    
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ch)
        {
            str[j++] = str[i];
        }
    }
    
    str[j] = '\0';
}

int stringareequal(char str1[], char str2[], char ch)
{
    removecharacter(str1, ch);
    removecharacter(str2, ch);
    
    return strcmp(str1, str2) == 0;
}

int main()
{
    char str1[100], str2[100];
    char ch;

    // User input
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;  // Remove newline if present

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;  // Remove newline if present

    printf("Enter character to remove: ");
    scanf(" %c", &ch);

    // Check if strings are equal after character removal
    if (stringareequal(str1, str2, ch)) 
    {
        printf("The strings are equal after removing '%c'.\n", ch);
    }
    else 
    {
        printf("The strings are NOT equal after removing '%c'.\n", ch);
    }

    return 0;
}