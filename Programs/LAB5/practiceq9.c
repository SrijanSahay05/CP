#include <stdio.h>

int main() {
  int option_index;
  double temp;
  printf("Enter an option index: ");
  scanf("%d", &option_index);
  switch (option_index) {
  case 1: // C->F || temp?-273.15
    printf("Enter a temperature in Celsius: ");
    scanf("%lf", &temp);
    while (temp <= -273.15) {
      printf("Enter a temperature in Celsius (that is greater than 273.15: ");
      scanf("%lf", &temp);
    }
    printf("Temperature in Fahrenheit: %f\n", (temp * 9 / 5) + 32);
    break;

  case 2:
    printf("Enter a temperature in Fahrenheit: ");
    scanf("%lf", &temp);
    while (temp <= -459.67) {
      printf(
          "Enter a temperature in Fahrenheit (that is greater than 459.67): ");
      scanf("%lf", &temp);
    }
    printf("Temperature in Celsius: %f\n", ((temp - 32) * 5) / 9);
    break;
  case 3:
    printf("Exiting Program...\n");
    break;
  default:
    printf("Invalid option index\n");
    main();
  }
}
