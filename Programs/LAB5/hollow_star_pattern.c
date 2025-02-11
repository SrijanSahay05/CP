#include <stdio.h>

int main() {
  int n;
  printf("Enter the number of rows: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (2 * n) - 1; j++) {
      // printf("i=%d , j=%d \t", i, j);
      if (i == 0) {
        printf("*");
      } else if (i == j) {
        printf("*");
      } else if (j == 2 * n - 2 - i) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}
