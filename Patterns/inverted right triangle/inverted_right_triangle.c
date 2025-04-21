// Pattern list
// *****
// ****
// ***
// **
// *

// 55555
// 4444
// 333
// 22
// 1

// 12345
// 1234
// 123
// 12
// 1

// AAAAA
// BBBB
// CCC
// DD
// E

// ABCDE
// ABCD
// ABC
// AB
// A

#include <stdio.h>
int startriangle(int rows)
{
    int i, j;
    for(i = rows; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int numberrowtriangle(int rows)
{
    int i, j;
    for(i = rows; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            printf("%d", i);
        }
        printf("\n");
    }
}

int numbercoltriangle(int rows)
{
    int i, j;
    for(i = rows; i > 0; i--)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
}

int alphabetcoltriangle(int rows)
{
    int i, j;
    for(i = rows; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            printf("%c", 'A' + j);
        }
        printf("\n");
    }
}

int alphabetrowtriangle(int rows)
{
    int i, j;
    for(i = rows; i >= 1; i--)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%c", 'A' + (rows - i));
        }
        printf("\n");
    }
}

int main()
{
    int i, j, rows;
    printf("Enter the no.of rows:");
    scanf("%d", &rows);
    
    int starprint = startriangle(rows);
    int numberrowsprint = numberrowtriangle(rows);
    int numbercolprint = numbercoltriangle(rows);
    int alphabetrowprint = alphabetrowtriangle(rows);
    int alphabetcolprint = alphabetcoltriangle(rows);

    return 0;
}
