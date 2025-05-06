/*
String Compression: Write a function that compresses a string (e.g., "aaabb" -> "a3b2")

Algorithm:
1. Iterate through the string and keep track of character frequencies.
2. Construct a new string using the character followed by its count.
3. Compare lengths: If the compressed string is shorter, return it; otherwise, return the original.

Example:
Original: aaabbccc
Compressed: a3b2c3
*/

#include <stdio.h>
#include <string.h>

void compress(const char *input, char *output)
{
    int len = strlen(input);
    int index = 0; // index for the output string
    
    for(int i = 0; i < len; i++)
    {
        output[index++] = input[i]; // store thr character
        int count = 1;
        
        while(i + 1 < len && input[i] == input[i + 1])
        {
            count++;
            i++;
        }
    
        // convert count to string and append
        int tempindex = index;
        if(count > 1)
        {
            sprintf(&output[index], "%d", count);
            index += strlen(&output[tempindex]);
        }
        
    }
    output[index] = '\0';
    
    // If compressed string is longer, copy original
    if (strlen(output) >= len) 
    {
        strcpy(output, input);
    }
}

int main()
{
    char str[] = "aaabbccc";
    char compressed[100];  // Output buffer

    printf("Original: %s\n", str);
    
    compress(str, compressed);
    
    printf("Compressed: %s\n", compressed);

    return 0;
}
