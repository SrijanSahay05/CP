#include <stdio.h>

void sortAscending(float arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main() {
  float arr[10];
  for (int i = 0; i < 10; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%f", &arr[i]);
  }
  sortAscending(arr, 10);
  printf("Sorted array: ");
  for (int i = 0; i < 10; i++) {
    printf("%f ", arr[i]);
  }
  printf("Maximum element: %f\n", arr[9]);
  printf("Second Maximum element: %f\n", arr[8]);
  printf("Minimum element: %f\n", arr[0]);
  printf("Second Minimum element: %f\n", arr[1]);
  printf("Avg of max, 2nd max, min, 2 min: %f\n",
         (arr[9] + arr[8] + arr[0] + arr[1]) / 4);
  return 0;
}
