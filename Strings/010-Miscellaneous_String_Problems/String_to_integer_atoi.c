// **Convert String to Integer (atoi):** Write a function that converts a string to an integer (atoi implementation).

#include <stdio.h>
#include <ctype.h>

int myAtoi(const char *str)
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
    char input[] = "        -12345abc";
    int num = myAtoi(input);
    printf("Converted integer: %d\n", num);
    return 0;
}
