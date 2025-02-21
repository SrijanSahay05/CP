#include <stdio.h>

int IsArmstrong(int n) {
  int sum = 0;
  int temp = n;
  while (n) {
    sum += (n % 10) * (n % 10) * (n % 10);
    n /= 10;
  }
  return sum == temp;
}

int main() {
  int startIndex, endIndex;
  printf("Enter the start index: ");
  scanf("%d", &startIndex);
  printf("Enter the end index: ");
  scanf("%d", &endIndex);
  for (int i = startIndex; i <= endIndex; i++) {
    if (IsArmstrong(i)) {
      printf("%d is an Armstrong number\n", i);
    }
  }
  return 0;
}
