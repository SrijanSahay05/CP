#include <stdio.h>

int main() {
  int num, rev = 0, temp, rem, i;
  printf("Enter a number: ");
  scanf("%d", &num);
  temp = num;
  while (temp > 0) {
    rev = rev * 10 + temp % 10;
    temp = temp / 10;
  }
  char *result = num == rev ? "Palindrome" : "Not Palindrome";
  printf("%d is %s\n", num, result);
  return 0;
}
