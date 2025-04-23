#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to convert a string to lowercase using ASCII codes
void convertLowerASCII(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A'); // Add the difference between 'a' and 'A'
        }
    }
}

// Function to convert a string to lowercase using the tolower() function
void convertLower(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char str1[100];
    char str2[100];

    // Get input string from the user
    printf("Enter a string: ");
    scanf("%99[^\n]", str1); // Read up to 99 characters or until a newline

    // Copy the input string to str2 before converting it.
    strcpy(str2, str1);

    // Convert to lowercase using ASCII codes
    convertLowerASCII(str1);
    printf("Lowercase string using ASCII: %s\n", str1);

    // Convert to lowercase using tolower()
    convertLower(str2);
    printf("Lowercase string using tolower(): %s\n", str2);

    return 0;
}
