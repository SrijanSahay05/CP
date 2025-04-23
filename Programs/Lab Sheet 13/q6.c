#include <stdio.h>
#include <stdbool.h>

// Function to compare two strings (returns -1 if str1 < str2, 0 if equal, 1 if str1 > str2)
int compareStrings(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] != '\0') {
        return -1;
    } else if (str1[i] != '\0' && str2[i] == '\0') {
        return 1;
    }
    return 0;
}

// Function to copy a string
void copyString(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Function to concatenate two strings with a space between them
void concatenateStrings(char dest[], const char src1[], const char src2[]) {
    int i = 0, j = 0;
    
    // Copy first string
    while (src1[i] != '\0') {
        dest[j++] = src1[i++];
    }
    
    // Add a space between strings
    dest[j++] = ' ';
    
    // Copy second string
    i = 0;
    while (src2[i] != '\0') {
        dest[j++] = src2[i++];
    }
    dest[j] = '\0';
}

int main() {
    char s1[100], s2[100], s3[200]; // Increased size of s3 to hold both strings.

    // Get input strings from the user
    printf("Enter string S1: ");
    scanf("%99[^\n]", s1); // Read up to 99 characters
    printf("Enter string S2: ");
    scanf(" %99[^\n]", s2); // Read up to 99 characters

    int comparisonResult = compareStrings(s1, s2);

    if (comparisonResult < 0) {
        concatenateStrings(s3, s1, s2); // s1 comes before s2 alphabetically
    } else if (comparisonResult > 0) {
        concatenateStrings(s3, s2, s1); // s2 comes before s1 alphabetically
    } else {
        copyString(s3, s1); // Strings are equal, copy either s1 or s2
    }

    printf("S3 = %s\n", s3);

    return 0;
}
