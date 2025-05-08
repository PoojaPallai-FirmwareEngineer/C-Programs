// Generate all possible substrings of a given string.

#include <stdio.h>
#include <string.h>

void substrings(char *str)
{
    int len = strlen(str);
    
    // Outer loop for starting character
    for(int start = 0; start < len; start++)
    {
        // Inner loop for ending character
        for(int end = 0; end < len; end++)
        {
            for(int k = start; k <= end; k++)
            {
                // Print the character
                printf("%c", str[k]);
            }
            printf("\n");
        }
    }
}

int main()
{
    char str[] = "abc";
    
    //printf("Orignial string:%s\n", str);
    
    substrings(str);
    
    //printf("All possible the string:%s\n", str);
    
    return 0;
}