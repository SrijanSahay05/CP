#include <stdio.h>

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
void selectionSort(int arr[], int n) {
  int i, j, min;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
  }
}

int main() {
  int a[] = {5, 2, 6, 1, 3, 4};
  int size = sizeof(a) / sizeof(a[0]);
  printf("Original array: \n");
  print_array(a, size);
  selectionSort(a, size);
  printf("Sorted array: \n");
  print_array(a, size);
  return 0;
}
