#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayMenu();
void playGame();
int generateRandomNumber(int min, int max);
int checkGuess(int guess, int target);
void provideHint(int guess, int target);
void displayRules();

int main() {
    int choice;
    
    printf("=== NUMBER GUESSING GAME ===\n");
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                displayRules();
                break;
            case 3:
                printf("Thank you for playing!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
    
    return 0;
}

void displayMenu() {
    printf("\n1. Play Game\n");
    printf("2. View Rules\n");
    printf("3. Exit\n");
    printf("==========================\n");
}

void displayRules() {
    printf("\n=== GAME RULES ===\n");
    printf("1. The computer will generate a random number between 1 and 100\n");
    printf("2. You have to guess the number\n");
    printf("3. You will get hints after each guess\n");
    printf("4. Try to guess the number in minimum attempts\n");
    printf("5. Type 0 to quit the current game\n");
    printf("==================\n");
}

void playGame() {
    int target, guess, attempts = 0;
    char playAgain;
    
    // Seed random number generator
    srand(time(NULL));
    
    do {
        target = generateRandomNumber(1, 100);
        attempts = 0;
        
        printf("\nI'm thinking of a number between 1 and 100...\n");
        
        do {
            printf("Enter your guess (0 to quit): ");
            scanf("%d", &guess);
            
            if (guess == 0) {
                printf("Game quit!\n");
                break;
            }
            
            attempts++;
            
            if (checkGuess(guess, target) == 0) {
                printf("Congratulations! You guessed it in %d attempts!\n", attempts);
                break;
            } else {
                provideHint(guess, target);
            }
            
        } while (1);
        
        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    printf("Thanks for playing!\n");
}

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int checkGuess(int guess, int target) {
    if (guess == target) {
        return 0; // Correct guess
    } else if (guess < target) {
        return -1; // Too low
    } else {
        return 1; // Too high
    }
}

void provideHint(int guess, int target) {
    if (guess < target) {
        printf("Too low! Try a higher number.\n");
    } else {
        printf("Too high! Try a lower number.\n");
    }
    
    // Additional hint based on how close the guess is
    int difference = abs(guess - target);
    if (difference <= 5) {
        printf("You're very close!\n");
    } else if (difference <= 15) {
        printf("You're getting warmer!\n");
    } else {
        printf("You're quite far!\n");
    }
} 