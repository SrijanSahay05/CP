#include <stdio.h>

int main() {
  int n, i = 1;
  printf("Enter the number: ");
  scanf("%d", &n);
  do {
    printf("%d\n", i);
    i += 2;
  } while (i <= n);
  return 0;
}
