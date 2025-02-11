#include <stdio.h>

int main() {
  int num1, num2, num3, num4, largest, second_largest;
  printf("Enter 4 numbers: ");
  scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
  if (num1 >= num2) {
    largest = num1;
    second_largest = num2;
  } else {
    largest = num2;
    second_largest = num1;
  }
  if (num3 > largest) {
    second_largest = largest;
    largest = num3;
  } else if (num3 > second_largest) {
    second_largest = num3;
  }
  if (num4 > largest) {
    second_largest = largest;
    largest = num4;
  } else if (num4 > second_largest) {
    second_largest = num4;
  }
  printf("Largest pair is: %d %d\n", largest, second_largest);
  printf("Sum of largest pair is: %d\n", largest + second_largest);
}
