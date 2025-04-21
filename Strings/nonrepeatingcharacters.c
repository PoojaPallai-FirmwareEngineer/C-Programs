#include <stdio.h>
#include <string.h>

char firstNonRepeatingCharacter(char *str) {
    int count[256] = {0};  // Array to store count of each character
    int i;

    // Count occurrences of each character
    for (i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }

    // Find the first character with a count of 1
    for (i = 0; str[i] != '\0'; i++) {
        if (count[(unsigned char)str[i]] == 1) {
            return str[i];
        }
    }

    return '\0';  // Return null character if no non-repeating character found
}

int main() {
    char str[] = "siss";
    char result = firstNonRepeatingCharacter(str);

    if (result != '\0') {
        printf("The first non-repeating character is: %c\n", result);
    } else {
        printf("No non-repeating character found.\n");
    }

    return 0;
}
