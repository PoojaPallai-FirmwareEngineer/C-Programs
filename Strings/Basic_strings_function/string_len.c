// Write a function to find the length of a string

#include<stdio.h>
int str_length(char str[])
{
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