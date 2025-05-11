// **String to Zigzag Pattern:** Write a function to convert a string into a zigzag pattern on a given number of rows.

#include <stdio.h>
#include <string.h>

void printzigzag(char *str, int numrows) 
{
    int len = strlen(str);

    // If only one row or rows are more than or equal to the string length, print normally
    if (numrows <= 1 || numrows >= len) 
    {
        printf("%s\n", str);
        return;
    }

    // Declare a 2d character array to hold the zigzag pattern
    char result[numrows][len];

    // Initialize the array with spaces to maintain structure when printing
    for (int i = 0; i < numrows; i++) 
    {
        for (int j = 0; j < len; j++) 
        {
            result[i][j] = ' '; // Fill with space initially
        }
    }

    int row = 0; // Start at the 1st row
    int down = 1; // Direction flag: 1 for down, 0 for up

    // Place each character in the appropriate position in the zigzag
    for (int col = 0; col < len; col++) 
    {
        result[row][col] = str[col]; // Put the character in the current row and column
        
        // Change direction when reaching the top or bottom row
        if (row == 0)
            down = 1; // Go down
        else if (row == numrows - 1)
            down = 0; // Go up
        
        // Update the row index depending on the direction
        row += down ? 1 : -1;
    }

    // Print the zigzag pattern (only print non-space characters)
    printf("Pattern:\n");
    for (int i = 0; i < numrows; i++) 
    {
        for (int j = 0; j < len; j++) 
        {
            if (result[i][j] != ' ') 
            {
                printf("%c", result[i][j]);
            } 
            else 
            {
                printf(" "); // Maintain the structure with proper spaces
            }
        }
        printf("\n");
    }

    // Construct the final output by reading the characters row by row
    printf("\nOutput: ");
    for (int col = 0; col < len; col++) 
    {
        for (int i = 0; i < numrows; i++) 
        {
            if (result[i][col] != ' ') 
            {
                printf("%c", result[i][col]);
            }
        }
    }
    printf("\n");
}

int main() {
    char str[] = "PAYPALISHIRING";
    int numRows = 3;
    
    printzigzag(str, numRows);

    return 0;
}
