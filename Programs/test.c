#include <stdio.h>

void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }

    int binary = 0;
    int placeValue = 1;

    while (decimal > 0) {
        binary += (decimal % 2) * placeValue;
        decimal = decimal / 2;
        placeValue *= 10;
    }

    printf("%d", binary);
}

int main() {
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Binary representation: ");
    decimalToBinary(decimal);
    printf("\n");

    return 0;
}
