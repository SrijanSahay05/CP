#include <stdio.h>
#include <string.h>
#include <stdbool.h> // Include stdbool.h for the bool type

// Function to check if a word exists in a sentence, count occurrences, and remove them (without string functions)
void processSentenceNoStringFunctions(char sentence[], char word[]) {
    int sentence_len = 0, word_len = 0, word_count = 0;
    int i, j, k;

    // Calculate the length of the sentence
    while (sentence[sentence_len] != '\0') {
        sentence_len++;
    }

    // Calculate the length of the word
    while (word[word_len] != '\0') {
        word_len++;
    }

    // Check if the word exists in the sentence and count occurrences, remove the word
    for (i = 0; i < sentence_len; i++) {
        int match = 1;
        if (i + word_len <= sentence_len) {
            for (j = 0; j < word_len; j++) {
                if (sentence[i + j] != word[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                word_count++;
                // Remove the word by shifting the remaining part of the sentence
                for (k = i; k < sentence_len - word_len; k++) {
                    sentence[k] = sentence[k + word_len];
                }
                sentence_len -= word_len;
                i--; // Adjust i to account for the shifted characters
            }
        }
    }

    // Print the results
    printf("Without string functions:\n");
    printf("The word occurs %d times in the sentence.\n", word_count);
    printf("Modified sentence: %s\n", sentence);
}

// Function to check if a word exists in a sentence, count occurrences, and remove them (with string functions)
void processSentenceWithStrings(char sentence[], char word[]) {
    int word_count = 0;
    char *temp = sentence;
    char *found;

    // Use strstr to find the first occurrence of the word
    while ((found = strstr(temp, word)) != NULL) {
        word_count++;
        // Calculate the index of the found word
        int index = found - sentence;
        // Shift the remaining part of the sentence to remove the word
        strcpy(found, found + strlen(word));
        temp = sentence; // Reset temp to the beginning of the sentence

    }

     printf("\nWith string functions:\n");
    printf("The word occurs %d times in the sentence.\n", word_count);
    printf("Modified sentence: %s\n", sentence);
}

int main() {
    char sentence[1000];
    char word[100];
    char sentenceCopy[1000]; // Make a copy to use with the other function

    // Get input from the user
    printf("Enter an English sentence: ");
    scanf(" %999[^\n]", sentence); // Read up to 999 characters
    printf("Enter an English word: ");
    scanf(" %99[^\n]", word);    // Read up to 99 characters

     // Copy the sentence for the version that uses string functions
    strcpy(sentenceCopy, sentence);

    // Process the sentence without string functions
    processSentenceNoStringFunctions(sentence, word);

    // Process the sentence with string functions
    processSentenceWithStrings(sentenceCopy, word);

    return 0;
}
