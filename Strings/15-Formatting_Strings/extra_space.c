// **Print "My Name Is Beautiful" with increasing spaces between words** <!-- Example: My  Name   Is    Beautiful. -->
// Original String: My Name Is Beautiful
// Extra spaces (1): My  Name  Is  Beautiful
// Extra spaces (2): My   Name   Is   Beautiful
// Extra spaces (3): My    Name    Is    Beautiful
// Extra spaces (4): My     Name     Is     Beautiful
// Extra spaces (5): My      Name      Is      Beautiful

#include <stdio.h>

void extraspaces(char *str, int space_count)
{
    char result[100];
    int index = 0;
    
    for(int i = 0; str[i] != '\0'; i++)
    {
        result[index++] = str[i];
        
        if(str[i] == ' ')
        {
            for(int j = 0; j < space_count; j++)
            {
                result[index++] = ' ';
            }
        }
    }
    result[index] = '\0';
    printf("Extra spaces (%d): %s\n", space_count, result);
}

int main()
{
    char str[] = "My Name Is Beautiful";
    
    printf("Original String: %s\n", str);
    
    for (int spaces = 1; spaces <= 5; spaces++) 
    {
        extraspaces(str, spaces);
    }
}
