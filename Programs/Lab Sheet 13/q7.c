#include <stdio.h>
#include <ctype.h>
#include <string.h>
void analyzeTextGets(char text[]) {
    int vowels = 0, consonants = 0, digits = 0, others = 0;
    int i = 0;

    while (text[i] != '\0') {
        char ch = text[i];
        if (isalpha(ch)) {
            ch = tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        } else if (isdigit(ch))
            digits++;
        else
            others++;
        i++;
    }
    printf("Using gets:\n");
    printf("Vowels: %d\nConsonants: %d\nDigits: %d\nOthers: %d\n", vowels, consonants, digits, others);
}

void analyzeTextScanf(char text[]) {
    int vowels = 0, consonants = 0, digits = 0, others = 0;
    int i = 0;

    //reset the array
    for(int k = 0; k < 1000; k++){
        text[k] = '\0';
    }

     scanf(" %999[^\n]", text);

    while (text[i] != '\0') {
        char ch = text[i];
        if (isalpha(ch)) {
            ch = tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        } else if (isdigit(ch))
            digits++;
        else
            others++;
        i++;
    }
    printf("Using scanf:\n");
    printf("Vowels: %d\nConsonants: %d\nDigits: %d\nOthers: %d\n", vowels, consonants, digits, others);
}

int main() {
    char text1[1000];
    char text2[1000];

    printf("Enter a line of text: ");
    fgets(text1, sizeof(text1), stdin);
    text1[strcspn(text1, "\n")] = 0;

    analyzeTextGets(text1);

    printf("Enter a line of text: ");
    analyzeTextScanf(text2);

    return 0;
}
