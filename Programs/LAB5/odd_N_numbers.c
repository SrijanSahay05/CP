#include <stdio.h>

int main() {
  int num = 1;
  while (num <= 100) {
    (num % 2) ? printf("%d\n", num) : 0;
    // num++;
    ++num;
  }
  return 0;
}
