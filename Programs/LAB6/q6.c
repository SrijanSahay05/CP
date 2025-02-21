#include <stdio.h>

int checkprime(int num) {
  if (num == 1) {
    return 0;
  }
  for (int i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  printf("Enter number: ");
  scanf("%d", &n);
  checkprime(n) ? printf("Prime \n") : printf("Not Prime \n");
}
