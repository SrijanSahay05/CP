#include <math.h>
#include <stdio.h>
int isArmStrong(int n) {
  int temp = n;
  int sum = 0;
  int num_digits = 0;
  while (temp > 0) {
    num_digits++;
    temp /= 10;
  }

  temp = n;
  while (temp > 0) {
    sum += pow(temp % 10, num_digits);
    temp /= 10;
  }
  return sum == n;
}

int main() {
  int lower_bound, upper_bound;
  printf("Enter lower bound: ");
  scanf("%d", &lower_bound);
  printf("Enter upper bound: ");
  scanf("%d", &upper_bound);
  printf("Armstrong numbers in the range %d to %d are: ", lower_bound,
         upper_bound);
  for (int i = lower_bound; i <= upper_bound; i++) {
    if (isArmStrong(i)) {
      printf("%d ", i);
    }
  }
  return 0;
}
