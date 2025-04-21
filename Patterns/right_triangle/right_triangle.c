// Right angle triangle using various ways.
// Patterns list are 

// *
// **
// ***
// ****
// *****

// A
// BB
// CCC
// DDDD
// EEEEE
// FFFFFF

// 1
// 22
// 333
// 4444
// 55555

// 1
// 12
// 123
// 1234
// 12345

// 2
// 34
// 456
// 5678
// 678910

// 0
// 10
// 010
// 1010
// 01010

#include <stdio.h>
int starrighttriangle(int rows)
{
    int i, j;
    for(i = 0; i <= rows; i++)
    {
        for(j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int numbertriangle(int rows)
{
    int i, j;
    for(i = 1; i <= rows; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%d", i);
        }
        printf("\n");
    }
}

int numberhortinaltriangle(int rows)
{
    int i, j;
    for(i = 1; i <= rows; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
}

int consectivenumbertriangle(int rows)
{
    int i, j;
    for(i = 1; i <= rows; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%d", (i + j));
        }
        printf("\n");
    }
}

int number01triangle(int rows)
{
    int i, j;
    for(i = 1; i <= rows; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%d", (i + j) % 2);
        }
        printf("\n");
    }
}

int alphabetrighttraingle(int rows)
{
    int i, j;
    char alphabet = 'A';
    for (i = 0; i <= rows; i++)
    {
        for(j = 0; j <= i; j++)
        printf("%c", alphabet);

        if (alphabet > 'Z')
        {
            //Reset the alphabet 'Z' to 'A'
            alphabet = 'A';
        }
        printf("\n");
        // It will be printing the alphabets in vertical format.
        // alphabet-- will result special characters
        alphabet++;
    }
}

int main()
{
    int i, j, rows;
    printf("Enter the no.of rows:");
    scanf("%d", &rows);
    
    int starprint = starrighttriangle(rows);
    int alphabetprint = alphabetrighttraingle(rows);
    int numberprint = numbertriangle(rows);
    int numbersprint = numberhortinaltriangle(rows);
    int consectivenumberprint = consectivenumbertriangle(rows); 
    int number01print = number01triangle(rows); 

    return 0;
}
