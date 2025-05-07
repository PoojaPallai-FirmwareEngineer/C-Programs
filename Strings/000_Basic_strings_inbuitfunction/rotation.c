// **String Rotation:** Write a function to check if one string is a rotation of another. 
// Given two strings, write a function to check if one is a rotation of the other.

// 🔁 String Rotation – Algorithm Using Built-in Functions

// Step 1: Check if the lengths of both strings are equal.
//         - If not equal, one cannot be a rotation of the other.
//         - Return false.

// Step 2: Concatenate the first string with itself.
//         - Example: If str1 = "abc", then str1 + str1 = "abcabc"

// Step 3: Check if str2 is a substring of the concatenated string using a built-in function.
//         - If yes, return true — str2 is a rotation of str1.
//         - If not found, return false — it's not a rotation.

// 🔁 String Rotation – Algorithm Without Using Built-in Functions

// Step 1: Check if the lengths of both strings are equal.
//         - If not equal, return false.

// Step 2: Loop through each index 'i' from 0 to (length - 1):
//         - This index 'i' is the assumed rotation point.

//         a. Compare characters from str1[i..end] with str2[0..length-i]
//            - Example: str1 = "abcde", str2 = "deabc"
//                      compare str1[2..4] with str2[0..2]

//         b. Then compare characters from str1[0..i-1] with str2[length-i..end]
//            - Continue comparing character by character (no inbuilt substring)

//         c. If both parts match exactly, return true — str2 is a rotation of str1.

// Step 3: If no match is found after full loop, return false — not a rotation.


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
    // Step 1: Calculate the lengths of both strings
    int len1 = 0, len2 = 0;

    // Manually calculate the length of str1
    while (str1[len1] != '\0')
    {
        len1++;
    }

    // Manually calculate the length of str2
    while (str2[len2] != '\0')
    {
        len2++;
    }

    // Step 2: If lengths are not equal, they can't be rotations
    if (len1 != len2)
    {
        return 0; // Not a rotation
    }

    // Step 3: Try every possible rotation starting from index i
    for (int i = 0; i < len1; i++)
    {
        int j;

        // Compare each character of str2 with rotated str1
        for (j = 0; j < len2; j++)
        {
            // Use modulo to wrap around the end of str1
            if (str1[(i + j) % len1] != str2[j])
            {
                break; // Mismatch found, break inner loop
            }
        }

        // If full match found, it's a valid rotation
        if (j == len2)
        {
            return 1; // Rotation found
        }
    }

    // Step 4: No rotation matched
    return 0; // Not a rotation
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
