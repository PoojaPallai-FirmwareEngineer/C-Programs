// Conditional complication 
// 1. #ifdef
// 2. #else
// 3. #undef
// 4. #ifndef
// 5. #endif

#include <stdio.h>
#define FLAG  
int main()
{
    int a = 20, b = 4;
    #ifdef FLAG 
        printf("FLAG is defined\n");
        a++;
        b++;
    #endif
    #undef FLAG
    #ifndef FLAG
        printf("Preprocessor\n");
        a--;
        b--;
    #endif
    printf("a = %d b = %d\n", a, b);
    printf("Program completed\n");
}