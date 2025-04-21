// Program for bitwise arithmetic

#include <stdio.h>
int main()
{
    int a = 5, b = 3;
    
    printf("Bitwise AND (a & b): %d\n", a & b); 
    printf("Bitwise OR (a & b): %d\n", a | b);
    printf("Bitwise XOR (a ^ b): %d\n", a ^ b);  
    printf("Bitwise NOT: %d\n", ~a);
    printf("Bitwise Left shift (a << 1 ): %d\n", a << 1);  
    printf("Bitwise right shift (a << 1): %d\n", a >> 1);
}