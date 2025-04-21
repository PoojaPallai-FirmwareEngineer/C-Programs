// Patterns list
//    *****
//     ****
//      ***
//       **
//        *

//    11111
//     2222
//      333
//       44
//        5

//    00000
//     1111
//      222
//       33
//        4

//    12345
//     1234
//      123
//       12
//        1

//    01234
//     0123
//      012
//       01
//        0
     
//    AAAAA
//     BBBB
//      CCC
//       DD
//        E

//    ABCDE
//     ABCD
//      ABC
//       AB
//        A


#include<stdio.h>
int startriangle(int rows)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        // Print leading spaces
        for(j = 0; j < i; j++)
        {
            printf(" ");
        }
        // Print stars
        for(j = 0; j < rows - i; j++)
        {
            printf("*");
        }
        // Print next line
        printf("\n");
    }
}

int numberwith1triangle(int rows)
{
    int i, j;
    // Start i from 1 instead of 0
    for(i = 1; i <= rows; i++) 
    {
        // Printing the leading spaces
        // Adjust the loop to print spaces accordingly
        for(j = 1; j < i; j++)
        {
            printf(" ");
        }
        // Printing the numbers
        for(j = 1; j <= rows - i + 1; j++)
        {
            printf("%d", i);
        }
        // Print next line
        printf("\n");
    }
}

int numberwith0triangle(int rows)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < i; j++)
        {
            printf(" ");
        }
        for(j = 0; j < rows - i; j++)
        {
            printf("%d", i);
        }
        printf("\n");
    }
}

int numbercolwith1triangle(int rows)
{
    int i, j;
    for(i = 1; i <= rows; i++)
    {
        for(j = 1; j < i; j++)
        {
            printf(" ");
        }
        for(j = 1; j <= rows - i + 1; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
}

int numbercolwith0triangle(int rows)
{
    int i, j;
    for(i = 0; i <= rows; i++)
    {
        for(j = 0; j < i; j++)
        {
            printf(" ");
        }
        for(j = 0; j < rows - i; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
}

int alphabetcoltriangle(int rows)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        // Print leading spaces
        for(j = 0; j < i; j++)
        {
            printf(" ");
        }
        // Print stars
        for(j = 0; j < rows - i; j++)
        {
            printf("%c", 'A' + j);
        }
        // Print next line
        printf("\n");
    }
}

int alphabetrowtriangle(int rows)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        // Print leading spaces
        for(j = 0; j < i; j++)
        {
            printf(" ");
        }
        // Print stars
        for(j = 0; j < rows - i; j++)
        {
            printf("%c", 'A' + i);
        }
        // Print next line
        printf("\n");
    }
}

int main()
{
    int i, j, rows;
    printf("Enter the no.of rows:");
    scanf("%d", &rows);
    
    int rightaligedinvertedprint = startriangle(rows);
    int rightaligednumber1print = numberwith1triangle(rows);
    int rightaligednumber0print = numberwith0triangle(rows);
    int rightaligedcolwith1print = numbercolwith1triangle(rows);
    int rightaligedcolwith0print = numbercolwith0triangle(rows);
    int alphabetrowprint = alphabetrowtriangle(rows);
    int alphabetcolprint = alphabetcoltriangle(rows);

    return 0;
}