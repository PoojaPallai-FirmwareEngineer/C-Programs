#include <stdio.h>
void Register();
void Static();
void Extern();

int globalvar = 10; //Global variable

int main()
{
    int localVar = 5;
    printf("Local variable = %d\n", localVar);
    Register();
    Static();
    Extern();
    return 0;
}

void Register()
{
    //Suggests storing the variable in a CPU register
    register int regvar = 4;
    printf("Register variable = %d\n", regvar);
}

void Static()
{
    // Static variable retains its value between function calls.
    static int staticVar = 1;
    printf("Static variable = %d\n", staticVar);
    staticVar++;
}

void Extern()
{
    // It tells complier that global variable is defined somewhere else.
    extern int globalvar;
    printf("Global variable = %d\n", globalvar);
    globalvar++;
}