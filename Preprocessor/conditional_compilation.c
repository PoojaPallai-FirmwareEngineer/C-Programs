// Conditional complication 
// 1. #ifdef
// 2. #else
// 3. #endif

#include <stdio.h>
#define FLAG 2 // Depends on this 
int main()
{
    int a = 1, b = 2;
    #if FLAG >= 3
        printf("Value of FLAG is greater than or equal to 3\n");
        a = a + b;
        b = a - b;
        printf("Value of variables are changed\n");
    #else
        printf("values less than 3\n");
        a = a / b;
        b = a - b;
        printf("Value of variables are changed\n"); 
    #endif
    printf("a = %d b = %d\n", a, b);

}