#include <stdio.h>

long long fibonacci_iterative(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }

  long long a = 0;
  long long b = 1;
  long long c = 0;

  for (int i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}

long long fibonacci_recursive(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Please enter a non-negative integer.\n");
    return 1;
  }

  printf("Fibonacci number at position %d using iterative method: %lld\n", n,
         fibonacci_iterative(n - 1));
  printf("Fibonacci number at position %d using recursive method: %lld\n", n,
         fibonacci_recursive(n - 1));

  return 0;
}
