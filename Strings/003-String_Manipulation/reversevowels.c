// **Reverse only the vowels in a given string.** <!-- Input: "beautiful" Output: "buetifal" -->

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isvowel(char ch)
{
    ch = tolower(ch);
    return (ch == 'a'|| ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void reverse(char *str)
{
    // Initialize two pointers: one from the start and one from the end of the string
    int right = strlen(str) - 1;
    int left = 0;
    
    // Continue until the two pointers meet or cross
    while(left < right)
    {
        // Move the left pointer to the next vowel (skip consonants)
        while(left < right && !isvowel(str[left]))
        {
            left++;
        }
        
        // Move the right pointer to the previous vowel (skip consonants)
        while(left < right && !isvowel(str[right]))
        {
            right--;
        }
        
        // If both pointers point to vowels, swap them
        if(left < right)
        {
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;

            // Move both pointers inward
            left++;
            right--;
        }
    }
}



int main()
{
    char str[] = "Hello";
    printf("Orignial string:%s\n", str);
    
    reverse(str);
    
    printf("reverse the string:%s\n", str);
    
    return 0;
}