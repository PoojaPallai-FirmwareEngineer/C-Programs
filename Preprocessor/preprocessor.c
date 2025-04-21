// Preprocessor list that is covered in this program
// 1. Symbolic constant 
// 2. Parameterized macros with arguments
// 3. Macros with functions
// 4. Stringizing operator
// 5. token paising operator

#include <stdio.h>

// Symbolic constant
#define MSSG "I understand the use of #define\n" 

// Parameterized macros with arguments
#define SUM(x,y) ((x) + (y))
#define PRODUCT(x,y) ((x) * (y)) 

// SWAP macros
// dtype is data type
#define SWAP(dtype, x, y) do {    \
    dtype temp = x;               \
    x = y;                        \
    y = temp;                     \
} while (0)


// Stringizing operator
#define STRINGFY(x) #x

// token pasting operator
#define CONCAT(a, b) a##b
        
void macromessage()
{
    // Macro is defined we are print the latest the macro.
    printf(MSSG);
}

void parameterizedmacro()
{
    // Using the sum and product macros
    int a = 5, b = 10;
    int sum_result = SUM(a,b);
    int product_result = PRODUCT(a, b);
    int sum_number_result = SUM(2, 4);
    int product_number = PRODUCT(3, 8);
    printf("sum and product = %d, %d, %d, %d\n", sum_result, product_result, sum_number_result, product_number);
}

void sawpmacros()
{
    int a = 40 , b = 30;
    SWAP(int, a, b); // Use macro using integer type
    printf("The result is: %d %d\n", a, b);
}

void stringoperator()
{
    int num = 100;
    printf("The value of num = %s\n", STRINGFY(num));
    printf("The value of stringizing operator = %s\n", STRINGFY(100));
}

void token_macros()
{
    // Using the CONCAT macro to create a variable name
    int myVar1 = 10;
    int myVar2 = 20;
    printf("Value of myVar1: %d\n", CONCAT(myVar, 1));
    printf("Value of myVar1: %d\n", CONCAT(myVar, 2));
}

int main()
{
    macromessage();
    parameterizedmacro();
    sawpmacros();
    stringoperator();
    token_macros();
}
