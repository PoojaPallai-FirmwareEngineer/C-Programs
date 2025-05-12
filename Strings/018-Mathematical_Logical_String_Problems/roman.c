// **Convert a Roman numeral string to an integer.**
// Enter a Roman Numeral:XVI
// Integer value:16

#include <stdio.h>

// Function to return the integer value of a single Roman numeral character
int value(char r)
{
    switch(r)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0; // Default case for invalid characters (should not happen in valid Roman numerals)
    }
}

// Function to convert a Roman numeral string to an integer
int romanToInt(char *s)
{
    int total = 0;  // Initialize the total value of the Roman numeral
    int i = 0;      // Initialize index for traversing the input string
    
    // Traverse the Roman numeral string
    while(s[i])
    {
        int current = value(s[i]);       // Get integer value of current Roman numeral character
        int next = value(s[i + 1]);      // Get integer value of next Roman numeral character
        
        // If current value is less than next value, it's a subtractive combination like IV (4), IX (9), etc.
        if(current < next)
        {
            total += (next - current);   // Add the value of the subtractive combination to total
            i += 2;                     // Move to the next pair of characters
        }
        else
        {
            total += current;           // Otherwise, add the current character's value to total
            i++;                        // Move to the next character
        }
    }
    
    return total;   // Return the total integer value of the Roman numeral string
}


int main()
{
    char name[20];
    printf("Enter a Roman Numeral:");
    scanf("%s", name);
    
    int result = romanToInt(name);
    printf("Integer value:%d\n", result);
}
