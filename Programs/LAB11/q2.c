#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char answer[100];  // Allocate a fixed-size buffer for the input
    printf("Please type something: ");
    gets(answer);
    
    printf("you typed %s \n", answer);
    return 0;
} 