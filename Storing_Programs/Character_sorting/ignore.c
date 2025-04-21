// Sort characters in a string ignoring case

// Error:
// ignore.c:22:5: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
//    22 |     qsort(str, strlen(str), sizeof(char), caseInsenstitvecompare);
//  Include stdlib header file


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> 

int caseInsenstitvecompare(const void *a, const void *b)
{
    char CharA = tolower(*(const char *)a);
    char CharB = tolower(*(const char *)b);

    return CharA - CharB;
}

int main()
{
    char str[] = "SortingExample";
    
    printf("Original string: %s\n", str);
    
    // Sort the string using qsort with a custom comparator
    qsort(str, strlen(str), sizeof(char), caseInsenstitvecompare);
    
    printf("Sorted string (case-insensitive): %s\n", str);
    
    return 0;
}