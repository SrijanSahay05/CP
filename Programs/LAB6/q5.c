#include <stdio.h>

long long factorial_iterative(int num) {
  long long fact = 1;
  for (int i = 1; i <= num; i++) {
    fact *= i;
  }
  return fact;
}

long long sum_series_iterative(int num) {
  long long sum = 0;
  for (int i = 1; i <= num; i++) {
    sum += factorial_iterative(i) / i;
  }
  return sum;
}

long long factorial_recursive(int num) {
  if (num == 0) {
    return 1;
  }
  return num * factorial_recursive(num - 1);
}

long long sum_series_recursive(int num) {
  if (num == 0) {
    return 0;
  }
  return factorial_recursive(num) / num + sum_series_recursive(num - 1);
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  printf("Sum of the series using iterative method: %lld\n",
         sum_series_iterative(n));
  printf("Sum of the series using recursive method: %lld\n",
         sum_series_recursive(n));
  return 0;
}
