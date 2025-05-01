// **Zig-Zag Pattern (like Rail Fence)**
// Input - Programming 
// P   r   i  
//  r g a m n 
//   o   m   g

#include <stdio.h>
#include <string.h>

void printzigzag(char *str, int numrows)
{
    int len = strlen(str);

    // If only one row or rows are more than or equal to the string length, print normally
    if(numrows <= 1 || numrows >= len)
    {
        printf("%s\n", str);
        return;
    }

    // declare a 2d character array to hold the zig zag pattern
    char result[numrows][len];

    // initialize the array with spaces to maintain structure when printing
    for(int i = 0; i < numrows; i++)
    {
        for(int j = 0; j < len; j++)
        {
            result[i][j] = ' ';
        }
    }

    int row = 0; // start at the 1st row
    int down = 1; // direction flag: 1 for down, 0 for up

    // Place each character in the appropriate position in the zigzag
    for (int col = 0; col < len; col++) 
    {
        result[row][col] = str[col]; // Put the character in the current row and column
        
        // change direction when reaching the top or bottom row
        if (row == 0)
            down = 1; // go down 
        else if(row == numrows - 1)
            down = 0; // go up
        
        // update the row index depending on the direction
        row += down ? 1: -1;
    }

    // print the zig zag patterns 
    for(int i = 0; i < numrows; i++)
    {
        for(int j = 0; j < len; j++)
        {
            printf("%c", result[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char str[] = "Programming";  // Input string
    int rows = 3;                // Number of rows for zigzag pattern

    // Call the function to display zigzag pattern
    printzigzag(str, rows);

    return 0;
}