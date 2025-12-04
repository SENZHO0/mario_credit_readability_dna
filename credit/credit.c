#include <stdio.h>

int main() {
    long card;
    printf("Input card number: ");
    scanf("%ld", &card);

    long temp = card;
    int total = 0;
    int position = 0;

    while (temp > 0) {
        int number = temp % 10;

        if (position % 2 == 1) {
            number = number * 2;
            if (number > 9) {
                number = (number / 10) + (number % 10);
            }
        }

        total = total + number;
        temp = temp / 10;
        position = position + 1;
    }

    if (total % 10 != 0) {
        printf("INVALID\n");
        return 0;
    }

    long start = card;
    while (start > 99) {
        start = start / 10;
    }

    if ((start == 34 || start == 37) && position == 15) {
        printf("AMEX\n");
    } else if (start >= 51 && start <= 55 && position == 16) {
        printf("MASTERCARD\n");
    } else if ((start / 10 == 4) && (position == 13 || position == 16)) {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }

    return 0;
}
