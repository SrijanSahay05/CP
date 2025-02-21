#include <stdio.h>

float square(float x) { return x * x; }

float cube(float x) { return x * x * x; }

float areaOfCircle(float radius) { return 3.14 * radius * radius; }

int main() {
  int x;
  printf("Enter a number: ");
  scanf("%d", &x);
  printf("Square of %d is %f\n", x, square(x));
  printf("Cube of %d is %f\n", x, cube(x));
  printf("Area of circle with radius %d is %f\n", x, areaOfCircle(x));
  return 0;
}
