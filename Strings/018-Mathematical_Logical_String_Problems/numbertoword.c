// **Implement a function that converts a given number to words.** <!-- Input: 123 Output: "One Hundred Twenty-Three" -->

#include <stdio.h>
#include <string.h>

void append(char *dest, const char *src) 
{
    if (strlen(dest) > 0) 
    {
        strcat(dest, " ");
    }
    strcat(dest, src);
}


void numberToWords(int num, char *result) 
{
    const char *ones[]  = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                           "sixteen", "seventeen", "eighteen", "nineteen"};
    const char *tens[]  = {"", "", "twenty", "thirty", "forty", "fifty",
                           "sixty", "seventy", "eighty", "ninety"};

    result[0] = '\0'; // Clear result

    if (num == 0) 
    {
        strcpy(result, "zero");
        return;
    }

    if (num >= 1000) 
    {
        append(result, ones[num / 1000]);
        append(result, "thousand");
        num %= 1000;
    }

    if (num >= 100) 
    {
        append(result, ones[num / 100]);
        append(result, "hundred");
        num %= 100;
    }

    if (num >= 20) 
    {
        append(result, tens[num / 10]);
        num %= 10;
    } 
    else if (num >= 10) 
    {
        append(result, teens[num - 10]);
        return;
    }

    if (num > 0) 
    {
        append(result, ones[num]);
    }
}

int main() {
    int number = 1234;
    char result[100];
    numberToWords(number, result);
    printf("%d in words is: %s\n", number, result);
    return 0;
}

