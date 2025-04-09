#include <stdio.h>
#include <stdlib.h>

// Function to swap first and last elements of an array
void fun1(int arr[], int size) {
    if (size < 2) return; // No need to swap if array has less than 2 elements
    
    int temp = arr[0];
    arr[0] = arr[size - 1];
    arr[size - 1] = temp;
}

// Function to print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("Part (a): Using static array\n");
    // Create and initialize a static array of size 10
    int static_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    printf("Static array before swap: ");
    printArray(static_arr, 10);
    
    // Call fun1 to swap first and last elements
    fun1(static_arr, 10);
    
    printf("Static array after swap: ");
    printArray(static_arr, 10);
    
    printf("\nPart (b): Using dynamic array\n");
    // Create and initialize a dynamic array of size 10
    int *dynamic_arr = (int*)malloc(10 * sizeof(int));
    if (dynamic_arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Initialize dynamic array
    for (int i = 0; i < 10; i++) {
        dynamic_arr[i] = i + 1;
    }
    
    printf("Dynamic array before swap: ");
    printArray(dynamic_arr, 10);
    
    // Call fun1 to swap first and last elements
    fun1(dynamic_arr, 10);
    
    printf("Dynamic array after swap: ");
    printArray(dynamic_arr, 10);
    
    // Free the dynamically allocated memory
    free(dynamic_arr);
    
    return 0;
}
