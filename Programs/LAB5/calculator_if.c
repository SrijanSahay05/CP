#include <stdio.h>

int main() {
  int num1, num2;
  char op;
  printf("Enter the first number: ");
  scanf("%d", &num1);
  printf("Enter the operator: ");
  scanf(" %c", &op);
  printf("Enter the second number: ");
  scanf("%d", &num2);
  if (op == '+') {
    printf("%d %c %d = %d\n", num1, op, num2, num1 + num2);
  } else if (op == '-') {
    printf("%d %c %d = %d\n", num1, op, num2, num1 - num2);
  } else if (op == '*') {
    printf("%d %c %d = %d\n", num1, op, num2, num1 * num2);
  } else if (op == '/') {
    if (num2 == 0) {
      printf("Division by zero is not allowed\n");
    } else {
      printf("%d %c %d = %d\n", num1, op, num2, num1 / num2);
    }
  } else if (op == '%') {
    if (num2 == 0) {
      printf("Division by zero is not allowed\n");
    } else {
      printf("%d %c %d = %d\n", num1, op, num2, num1 % num2);
    }
  } else {
    printf("Invalid operator\n");
  }
  return 0;
}
