#include <stdio.h>

int main() {
  int n;
  int sum = 0;
  printf("Enter a number: ");
  scanf("%d", &n);
  if (n >= 0) {
    for (int i = n; i <= 2 * n; i++) {
      sum += i;
    }
    printf("The sum of the numbers between %d and %d is %d\n", n, 2 * n, sum);
  } else {
    for (int i = 2 * n; i >= 3 * n; i--) {
      sum += i;
    }
    printf("The sum of the numbers between %d and %d is %d\n", 2 * n, 3 * n,
           sum);
  }
  return 0;
}
