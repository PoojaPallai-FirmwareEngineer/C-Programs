// **Toggle the case of each character in a string.**

#include <stdio.h>
#include <string.h>

void toggle(char *str)
{
   int i = 0;
   
   while(str[i] != '\0')
   {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
           str[i] = str[i] - ('a' - 'A');
        }
       
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
           str[i] = str[i] + ('a' - 'A');
        }
        i++;
    }
    //i++; // If we give here then compiler will never come to here and do execution.
}

int main()
{
    char str[] = "Hello World";
    
    printf("Orignial string:%s\n", str);
    
    toggle(str);
    
    printf("Toggle the string:%s\n", str);
    
    return 0;
}