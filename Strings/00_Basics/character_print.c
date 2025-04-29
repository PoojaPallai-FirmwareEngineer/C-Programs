// Prints characters of a string and address of each characters

#include <stdio.h>
int main()
{
    char str[] = "India";
    int i;
    for(i = 0; str[i] != '\0'; i++)
    {
        printf("Character array of string:%c\n", str[i]);
        printf("Address of the string:%p\n", (void *)&str[i]);
    }
    return 0;
}

