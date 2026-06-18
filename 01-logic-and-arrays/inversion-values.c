#include <stdio.h>

void displayReverseOrder(int vector[], int size) {
    printf("Numbers in reverse order:\n");

    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", vector[i]);
    }

    printf("\n");
}

int main() {
    int quantity;

    printf("How many values would you like to enter? ");
    scanf("%d", &quantity);

    int vector[quantity];

    for (int i = 0; i < quantity; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    displayReverseOrder(vector, quantity);

    return 0;
}
