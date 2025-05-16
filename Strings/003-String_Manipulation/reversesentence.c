// **Reverse every word in a sentence but keep their order intact** <!-- Input: "Hello World" Output: "olleH dlroW" -->

#include <stdio.h>
#include <string.h>

void reverse(char *start, char *end)
{
    while(start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reversewordsentence(char *str)
{
    int length = strlen(str);
    char *start = str;
    char *end = str;
    
    for(int i = 0; i <= length; i++)
    {
        if(str[i] == ' ' || str[i] == '\0')
        {
            reverse(start, end - 1);
            start = end + 1;
        }
        end++;
    }
}

int main()
{
    char str[] = "Hello World";
    printf("Orignial string:%s\n", str);
    
    reversewordsentence(str);
    
    printf("reverse string:%s\n", str);
    
    return 0;
}