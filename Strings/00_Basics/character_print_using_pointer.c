// Prints characters of a string and address of each characters using pointer

#include <stdio.h>
int main()
{
    char str[] = "India";
    char *p;
    p = str;
    while(*p != '\0')
    {
        printf("Character array of string:%c\n", *p);
        printf("Address of the string:%p\n", (void *)p);
        p++;
    }
    return 0;
}

