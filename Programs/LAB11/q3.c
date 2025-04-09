#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    int *arr1, *arr2;
    int dot_product = 0;
    
    // Get array size from user
    printf("Enter the size: ");
    scanf("%d", &size);
    
    // Allocate memory for both arrays
    arr1 = (int*)malloc(size * sizeof(int));
    arr2 = (int*)malloc(size * sizeof(int));
    
    if (arr1 == NULL || arr2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Get elements of first array
    printf("Enter the elements of the first array\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr1[i]);
    }
    
    // Get elements of second array
    printf("Enter the elements of the second array\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr2[i]);
    }
    
    // Calculate dot product
    for (int i = 0; i < size; i++) {
        dot_product += arr1[i] * arr2[i];
    }
    
    // Print result
    printf("The dot product of the arrays is %d.\n", dot_product);
    
    // Free allocated memory
    free(arr1);
    free(arr2);
    
    return 0;
} 