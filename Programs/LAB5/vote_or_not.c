#include <stdio.h>

int main() {
  int age;
  printf("Enter your age: ");
  scanf("%d", &age);
  char *eligibility = (age >= 18) ? "Yes" : "No";
  printf("Eligible to vote? %s\n", eligibility);
  return 0;
}
