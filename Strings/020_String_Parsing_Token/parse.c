// **Parse CSV or semi-structured text**

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN        1024
#define MAX_FIELDS          100

int main()
{
    char line[MAX_LINE_LEN] = "John,Doe,30,New York,Developer\n";
    char *fields[MAX_FIELDS];
    int fieldsCount = 0;

    // Remove newline character if present
    line[strcspn(line, "\n")] = '\0';

    // Tokenie the line using comma as delimiter
    char *token = strtok(line, ",");

    while(token != NULL && fieldsCount < MAX_FIELDS)
    {
        fields[fieldsCount++] = token;
        token = strtok(NULL, ",");
    }

    // Print all parsed fields
    printf("Parsed CSV fields:\n");
    for (int i = 0; i < fieldsCount; i++)
    {
        printf("Field %d: %s\n", i + 1, fields[i]);
    }
}