#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int num_count;
    int *numbers;
    int i;
    double sum = 0.0;
    double average;

    // Open the file "numbers.txt" in read mode.
    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening file numbers.txt\n");
        return 1; // Return an error code
    }

    // Read the number of integers from the first line of the file.
    if (fscanf(file, "%d", &num_count) != 1) {
        printf("Error reading the number count from the file.\n");
        fclose(file);
        return 1;
    }

    if (num_count <= 0) {
        printf("Number count is not positive.\n");
        fclose(file);
        return 1;
    }
    // Dynamically allocate memory for the array of integers.
    numbers = (int *)malloc(num_count * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation error\n");
        fclose(file);
        return 1; // Return an error code if memory allocation fails.
    }

    // Read the integers from the file into the dynamically allocated array.
    for (i = 0; i < num_count; i++) {
        if (fscanf(file, "%d", &numbers[i]) != 1)
        {
            printf("Error reading number %d from the file.\n", i + 1);
            fclose(file);
            free(numbers);
            return 1;
        }
    }

    // Close the file after reading.
    fclose(file);

    // Calculate the sum of the numbers.
    for (i = 0; i < num_count; i++) {
        sum += numbers[i];
    }

    // Calculate the average.
    average = sum / num_count;

    // Display the average.
    printf("Average of the numbers: %.2f\n", average);

    // Free the dynamically allocated memory.
    free(numbers);

    return 0; // Indicate successful execution.
}
