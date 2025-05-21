// **Split string using multiple delimiters**

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "Iron-Man;Hulk|Thor,Captain-America";
    const char *delimiters = ";|,-"; // multiple delimiters
    char *token;

    // use strtok to split by multiple delimiters
    token = strtok(str, delimiters);
    while(token != NULL)
    {
        printf("Token: %s\n", token);
        token = strtok(NULL, delimiters);
    }

    return 0;
}