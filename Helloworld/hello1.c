// Hello world program using functions

// The function call into the main for hello world
// complication steps
// 1. gcc hello1.c -o hello1
// 2. ./hello1

// Some problem was there when I write the function down the main function. Errors will come. 
// To fix this, you can either:
// 1. Move the definition of fun above main.- declaration
// 2. Provide a forward declaration of fun before main.

#include <stdio.h>
// declaration
void fun(); 
// Main function
void main()
{
    fun();
}

// definition
void fun()
{
    printf("hello world\n");
}
