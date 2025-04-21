#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool ispalidrome(char *str)
{
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false; // No palindrome
        }
        left++;
        right--;
    }
    return true; //ispalidrome
}

int main()
{
    char str[100];
    printf("Enter the string:");
    scanf("%s", str);

    if (ispalidrome(str))
    {
        printf("'%s' is a palindrome.\n", str);
    } 
    else 
    {
        printf("'%s' is not a palindrome.\n", str);
    }
    return 0;
}