// Replace all spaces in a string with @20 (URL encoding)
// Input: "My name is John" Output: "My@20name@20is@20John"

#include <stdio.h>
#include <string.h>

void replacespaces(char *str)
{
    int length = strlen(str);
    int spacecount = 0;
    
    // count spaces in the input string 
    for(int i = 0; i < length; i++)
    {
        if(str[i] == ' ')
        {
            spacecount++;
        }
    }
    
    // New length after replacement 
    int newLen = length + spacecount * 2;
    str[newLen] = '\0';
    
    // Trasverse the end and replace the space with @20
    for(int i = length - 1, j = newLen - 1; i >= 0; i--)
    {
        if(str[i] == ' ')
        {
            str[j--] ='@';
            str[j--] ='2';
            str[j--] ='0';
        }
        else
        {
            str[j--] = str[i];
        }
    }
}

int main()
{
    char str[100] = "My name is John";
    printf("Orignial string:%s\n", str);
    
    replacespaces(str);
    
    printf("replace the string:%s\n", str);
    
    return 0;
}