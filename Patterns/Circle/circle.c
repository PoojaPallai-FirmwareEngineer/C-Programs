//Program to print circle and hollow circle
// execution step: gcc -o circle circle.c -lm

//Hollow circle 
//     * * *     
//   *       *   
// *           * 
// *           * 
// *           * 
//   *       *   
//     * * *  

// Full circle
//     * * *     
//   * * * * *   
// * * * * * * * 
// * * * * * * * 
// * * * * * * * 
//   * * * * *   
//     * * * 
  
#include <stdio.h>
#include <math.h>

void circle (int r)
{
    int i, j, x, y;
    float distance;
    for(i = 0; i <= 2 * r; i++)
    {
        for(j = 0; j <= 2 * r; j++)
        {   
            x = i - r;
            y = j - r;
            distance = sqrt(x * x + y * y);
            if (distance <= r + 0.5 && distance <= r + 0.5 ) //Prints whole circle with stars
            //if (fabs(distance - r) < 0.5) //Prints hollow circle
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

}

int main()
{
    int r = 3;
    circle(r);
    return 0;
}
