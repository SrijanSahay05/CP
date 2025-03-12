#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int binarySearch(int arr[], int n, int key) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

void selectionSortDec(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int max_index = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] > arr[max_index]) {
        max_index = j;
      }
    }
    if (max_index != i) {
      int temp = arr[i];
      arr[i] = arr[max_index];
      arr[max_index] = temp;
    }
  }
}

int main() {
  int key, result, n = 10;
  int choice, bool = 1;
  int arr[n];

  while (bool) {
    printf("Enter 1 for linear Search, 2 for Binary Search, 3 for Selection "
           "Sort, 4 to exit: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter 10 integer elements: ");
      for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
      }
      printf("Enter the element to search: ");
      scanf("%d", &key);
      result = linearSearch(arr, n, key);
      if (result == -1) {
        printf("Element not found\n");
      } else {
        printf("Element found at %dth index\n", result);
      }
      break;

    case 2:
      printf("Enter 10 integer elements in ascending order: ");
      for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
      }
      printf("Enter the element to search: ");
      scanf("%d", &key);
      // selectionSortDec(arr, n);
      // for(int i = 0; i < n / 2; i++){
      //     int temp = arr[i];
      //     arr[i] = arr[n-i-1];
      //     arr[n-i-1] = temp;
      // }
      result = binarySearch(arr, n, key);
      if (result == -1) {
        printf("Element not found\n");
      } else {
        printf("Element found at %dth index\n", result);
      }
      break;

    case 3:
      printf("Enter 10 integer elements: ");
      for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
      }
      selectionSortDec(arr, n);
      printf("Descending sorted array: ");
      for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
      }
      printf("\n");
      printf("Ascending sorted array: ");
      for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
      }
      printf("\n");
      break;

    case 4:
      printf("Bye Bye SearchNSort!\n");
      bool = 0;
      break;

    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}
