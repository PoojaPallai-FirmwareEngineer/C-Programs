#include <stdio.h>
#include <string.h>

int isrotationwithbuilt(const char *str1, const char *str2)
{
    // Check if the lengths are equal
    if (strlen(str1) != strlen(str2))
    {
        return 0; // Not a rotation
    }

    // Concatenate str1 with itself
    char concat[2 * strlen(str1) + 1];
    strcpy(concat, str1);
    strcat(concat, str1);  // Append str1 to itself

    // Check if str2 is a substring of the concatenated string
    return strstr(concat, str2) != NULL;
}

int isrotationwithoutinbuilt(const char *str1, const char *str2)
{
    // Calculate the lengths of both strings
    int len1 = 0, len2 = 0;

    while (str1[len1] != '\0')
    {
        len1++;
    }

    while (str2[len2] != '\0')
    {
        len2++;
    }

    // If lengths are not equal, they cannot be rotations
    if (len1 != len2)
    {
        return 0; // Not a rotation
    }

    // Check if str2 is a rotation of str1
    for (int i = 0; i < len1; i++)
    {
        int j;
        for (j = 0; j < len2; j++)
        {
            if (str1[(i + j) % len1] != str2[j])
            {
                break;
            }
        }
        if (j == len2)
        {
            return 1; // Found a match
        }
    }
    return 0;
}

int main()
{
    const char *str1 = "ABCD";
    const char *str2 = "CDAB";

    if (isrotationwithbuilt(str1, str2)) 
    {
        printf("%s is a rotation of %s\n", str2, str1);
    } 
    else 
    {
        printf("%s is not a rotation of %s\n", str2, str1);
    }

    if (isrotationwithoutinbuilt(str1, str2)) 
    {
        printf("Without inbuilt function %s is a rotation of %s\n", str2, str1);
    } 
    else 
    {
        printf("Without inbuilt function %s is not a rotation of %s\n", str2, str1);
    }
}
