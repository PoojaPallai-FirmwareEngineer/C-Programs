// **String to Number (parseInt):** Write a function to parse a string as a number.
// Enter a string to parse as an integer:    -456abc
// Parsed integer: -456

#include <stdio.h>
#include <ctype.h>

int parseint(const char *str)
{
    int result = 0;
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

    // Convert digits
    while (isdigt(*str))
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result * sign;
}

int main() 
{
    char input[100];
    printf("Enter a string to parse as an integer: ");
    fgets(input, sizeof(input), stdin);

    int number = parseInt(input);
    printf("Parsed integer: %d\n", number);

    return 0;
}
