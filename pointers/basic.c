#include<stdio.h>
int main()
{
    char var = 100;
    printf("The address of the var:%p\n", &var);

    char * pAddress = &var;
    char value = *pAddress;

    printf("read value is : %d\n", var);

    *pAddress = 65;
    printf("write value is : %d\n", var);

}