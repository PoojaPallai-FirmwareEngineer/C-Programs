// **String to Integer with Error Handling:** Implement a function that converts a string to an integer, but handles errors when the 
// string is not a valid integer.

#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int stringToInt(const char *str, int *result)
{
    // Null or empty string
    if (str == NULL || *str == '\0') return 0; 

    int sign = 1;

    // Skip whiteship
    while (isspace(*str))
    {
        str++;
    }

    // Handle optional sign
    if (*str == '-' || *str == '+')
    {
        if(*str == '-')
        {
            sign = -1;
        }
        str++;
    }

    // no digits after sign
    if (!isdigit(*str)) return 0; 

    // Use long to detect overflow
    long res = 0;

    while(*str)
    {
        // Invalid character found
        if(!isdigit(*str)) return 0; 

        result = result * 10 + (*str - '0');

        // Check for overflow
        if((sign == 1 && res > INT_MAX) || (sign == -1 && -res < INT_MIN))
            return 0;
        
        str++;
    }

    *result = (int)(result * sign);

    return 1;
}

int main() 
{
    const char *test = "  -1234";
    int value;

    if (stringToInt(test, &value)) 
    {
        printf("Converted value: %d\n", value);
    } 
    else 
    {
        printf("Invalid input: '%s'\n", test);
    }

    return 0;
}
