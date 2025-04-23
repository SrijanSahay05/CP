#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

int is_word_equal(const char *word1, const char *word2) {
    return strcmp(word1, word2) == 0;
}

int main() {
    char sentence[MAX_LEN], word[MAX_LEN];
    char temp[MAX_LEN];
    int count = 0;

    // Read sentence and word using scanf
    scanf("%[^\n]s", sentence);
    scanf(" %s", word);
    
    // Count occurrences and store word length
    int wordLen = 0;
    while (word[wordLen] != '\0') wordLen++;
    
    // Find occurrences
    for (int i = 0; sentence[i] != '\0'; i++) {
        int match = 1;
        for (int j = 0; j < wordLen; j++) {
            if (sentence[i + j] != word[j]) {
                match = 0;
                break;
            }
        }
        if (match && (i == 0 || sentence[i-1] == ' ') && 
            (sentence[i + wordLen] == ' ' || sentence[i + wordLen] == '\0')) {
            count++;
        }
    }
    
    printf("No. of occurrences of %s is %d\n", word, count);
    
    // Remove word occurrences
    printf("output string is: ");
    int i = 0;
    while (sentence[i] != '\0') {
        int match = 1;
        for (int j = 0; j < wordLen; j++) {
            if (sentence[i + j] != word[j]) {
                match = 0;
                break;
            }
        }
        
        if (match && (i == 0 || sentence[i-1] == ' ') && 
            (sentence[i + wordLen] == ' ' || sentence[i + wordLen] == '\0')) {
            i += wordLen;
            if (sentence[i] == ' ') i++;
        } else {
            printf("%c", sentence[i]);
            i++;
        }
    }
    printf("\n");
    
    return 0;
}