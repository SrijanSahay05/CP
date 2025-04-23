#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h> // For DBL_MAX

// Function to calculate the Euclidean distance between two points
double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    FILE *file;
    int numPoints;
    double (*pointsArray)[2]; // 2D array to store the points
    double (*closePointsArray)[4]; // 2D array to store closest point pairs (x1, y1, x2, y2)
    int i, j;

    // Open the file "twoDPoints.csv" in read mode
    file = fopen("twoDPoints.csv", "r");
    if (file == NULL) {
        printf("Error opening file twoDPoints.csv\n");
        return 1;
    }

    // Read the number of points from the first line of the file
    if (fscanf(file, "%d", &numPoints) != 1) {
        printf("Error reading the number of points from the file.\n");
        fclose(file);
        return 1;
    }

    if(numPoints <= 0) {
        printf("Number of points must be greater than 0.\n");
        fclose(file);
        return 1;
    }
    // Dynamically allocate memory for the pointsArray
    pointsArray = (double(*)[2])malloc(numPoints * sizeof(double[2]));
    if (pointsArray == NULL) {
        printf("Memory allocation error for pointsArray\n");
        fclose(file);
        return 1;
    }

    // Dynamically allocate memory for the closePointsArray
    closePointsArray = (double(*)[4])malloc(numPoints * sizeof(double[4]));
    if (closePointsArray == NULL) {
        printf("Memory allocation error for closePointsArray\n");
        free(pointsArray);
        fclose(file);
        return 1;
    }
    // Read the points from the file into the pointsArray
    for (i = 0; i < numPoints; i++) {
        if (fscanf(file, "%lf,%lf", &pointsArray[i][0], &pointsArray[i][1]) != 2) {
            printf("Error reading point %d from the file.\n", i + 1);
            fclose(file);
            free(pointsArray);
            free(closePointsArray);
            return 1;
        }
    }

    // Close the file
    fclose(file);

    // Find the closest point for each point
    for (i = 0; i < numPoints; i++) {
        double minDistance = DBL_MAX;
        int closestPointIndex = -1;

        for (j = 0; j < numPoints; j++) {
            if (i != j) { // Don't compare a point to itself
                double distance = calculateDistance(pointsArray[i][0], pointsArray[i][1], pointsArray[j][0], pointsArray[j][1]);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestPointIndex = j;
                }
            }
        }

        // Store the closest point pair in closePointsArray
        closePointsArray[i][0] = pointsArray[i][0];
        closePointsArray[i][1] = pointsArray[i][1];
        closePointsArray[i][2] = pointsArray[closestPointIndex][0];
        closePointsArray[i][3] = pointsArray[closestPointIndex][1];
    }

    // Print the closest point pairs
    printf("Closest point pairs:\n");
    for (i = 0; i < numPoints; i++) {
        printf("(%.2lf, %.2lf) is closest to (%.2lf, %.2lf)\n",
               closePointsArray[i][0], closePointsArray[i][1], closePointsArray[i][2], closePointsArray[i][3]);
    }

    // Free the dynamically allocated memory
    free(pointsArray);
    free(closePointsArray);

    return 0;
}

