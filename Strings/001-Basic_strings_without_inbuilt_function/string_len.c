// Write a function to find the length of a string

#include<stdio.h>
int str_length(char str[])
{
    // Logic can be done 
    // 1. Using while loop with pointer
    // 2. Using for loop with index
    // 3. Using for loop with pointer
    // 4. Using recursion
    // 5. Using do-while loop

    int length = 0;
    while(str[length] != '\0')
    {
        length++;
    }
    return length;
}

int main()
{
    char str[] = "Hello world!";
    int result = str_length(str);
    printf("Length of string:%d\n", result);
    return 0;   
}