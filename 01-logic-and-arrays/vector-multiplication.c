#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i, scalar;
    int *vector = NULL;

    printf("=== VECTOR MULTIPLICATION ===\n");

    // 1. Get vector size from user
    printf("Enter the size of the vector: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // 2. Dynamically allocate memory for the vector
    vector = (int*)malloc(size * sizeof(int));
    if (vector == NULL) {
        printf("Error: Memory allocation failed!\n");
        return 1;
    }

    // 3. Populate the vector
    printf("\n--- Populate the Vector ---\n");
    for (i = 0; i < size; i++) {
        printf("Enter value for position [%d]: ", i);
        if (scanf("%d", &vector[i]) != 1) {
            printf("Invalid input.\n");
            free(vector);
            return 1;
        }
    }

    // 4. Get the multiplier (scalar)
    printf("\nEnter the scalar value to multiply the vector by: ");
    if (scanf("%d", &scalar) != 1) {
        printf("Invalid scalar.\n");
        free(vector);
        return 1;
    }

    // 5. Calculate and display the results
    printf("\n--- Multiplication Results ---\n");
    printf("Original Vector: [ ");
    for (i = 0; i < size; i++) {
        printf("%d ", vector[i]);
    }
    printf("]\n");

    printf("Result Vector:   [ ");
    for (i = 0; i < size; i++) {
        // Multiply each element by the scalar
        printf("%d ", vector[i] * scalar);
    }
    printf("]\n");

    // 6. Free allocated memory
    free(vector);

    return 0;
}
