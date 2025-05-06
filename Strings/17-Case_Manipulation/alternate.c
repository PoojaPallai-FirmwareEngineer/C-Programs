//**Convert every alternate character of a string to uppercase.** <!-- Input: "interview" Output: "InTeRvIeW" -->

#include <stdio.h>
#include <string.h>

void alternate(char *str)
{
    int i = 0;
    
    while(str[i] != '\0')
    {
        if(i % 2 == 0 && str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - ('a' - 'A');
        }
        i++;
    }
}

int main()
{
    char str[] = "interview";
    
    printf("Orignial string:%s\n", str);
    
    alternate(str);
    
    printf("Alternate the string:%s\n", str);
    
    return 0;
}