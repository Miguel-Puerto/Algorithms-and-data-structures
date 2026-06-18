#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // Generates a secret number between 1 and 50
    int secretNumber = rand() % 50 + 1;
    int guess;
    int attempts = 10;
    int difference;

    printf("=== MENTALIST GAME ===\n");
    printf("Try to guess the secret number between 1 and 50.\n");

    // Main game loop
    while (attempts > 0) {

        printf("\nAttempts remaining: %d\n", attempts);
        printf("Enter your guess: ");
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }

        // Win condition
        if (guess == secretNumber) {
            printf("\nCongratulations! You guessed the correct number: %d!\n", secretNumber);
            return 0;
        }

        // Calculate absolute distance to give hot/cold hints
        difference = abs(secretNumber - guess);

        if (difference <= 12) {
            printf("You are close!\n");
        }
        else if (difference <= 25) {
            printf("You are getting there...\n");
        }
        else {
            printf("You are far away!\n");
        }

        // Higher/Lower direction hints
        if (guess < secretNumber) {
            printf("The secret number is higher.\n");
        } else {
            printf("The secret number is lower.\n");
        }

        attempts--;
    }

    // Game over condition
    printf("\nYou ran out of attempts!\n");
    printf("The secret number was: %d\n", secretNumber);

    return 0;
}
