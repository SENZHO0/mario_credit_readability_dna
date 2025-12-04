#include <stdio.h>

int main(void) {
    int height;
    int result;

    do {
        printf("Height (1-8): ");
        result = scanf("%d", &height);

        if (result != 1) {
            while (getchar() != '\n');
            height = 0;
        }

    } while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++) {
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }

        for (int j = 0; j < i; j++) {
            printf("#");
        }

        printf("  ");

        for (int j = 0; j < i; j++) {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
