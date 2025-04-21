/*
Program Find the XOR of all numbers from 1 to n
We can utilize the fact that there is a pattern in the XOR of numbers from 1 to n. 
The XOR of numbers from 1 to n follows this repeating pattern every 4 numbers:

If n % 4 == 0, then the result is n.
If n % 4 == 1, then the result is 1.
If n % 4 == 2, then the result is n + 1.
If n % 4 == 3, then the result is 0.
This is because the XOR of numbers follows a predictable cycle every 4 numbers.
*/


#include <stdio.h>
int xor1ton(int num)
{
    if (num % 4 == 0)
        return num;
    else if (num % 4 == 1)
        return 1;
    else if (num % 4 == 2)
        return num + 1;
    else
        return 0;
}

int main()
{
    int num;

    printf("Enter the num:");
    scanf("%u", &num);

    printf("XOR of numbers from 1 to %d is: %d\n", num, xor1ton(num));

}