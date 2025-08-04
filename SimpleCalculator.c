#include <stdio.h>

// Function prototypes
void displayMenu();
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
int modulus(int a, int b);
void performCalculation();

int main() {
    int choice;
    
    printf("=== SIMPLE CALCULATOR ===\n");
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                performCalculation();
                break;
            case 2:
                printf("Thank you for using Simple Calculator!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 2);
    
    return 0;
}

void displayMenu() {
    printf("\n1. Perform Calculation\n");
    printf("2. Exit\n");
    printf("=======================\n");
}

void performCalculation() {
    int choice;
    float num1, num2, result;
    int int1, int2, intResult;
    
    printf("\nSelect operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
        case 2:
        case 3:
        case 4:
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            
            switch (choice) {
                case 1:
                    result = add(num1, num2);
                    printf("%.2f + %.2f = %.2f\n", num1, num2, result);
                    break;
                case 2:
                    result = subtract(num1, num2);
                    printf("%.2f - %.2f = %.2f\n", num1, num2, result);
                    break;
                case 3:
                    result = multiply(num1, num2);
                    printf("%.2f * %.2f = %.2f\n", num1, num2, result);
                    break;
                case 4:
                    if (num2 != 0) {
                        result = divide(num1, num2);
                        printf("%.2f / %.2f = %.2f\n", num1, num2, result);
                    } else {
                        printf("Error: Division by zero!\n");
                    }
                    break;
            }
            break;
            
        case 5:
            printf("Enter first integer: ");
            scanf("%d", &int1);
            printf("Enter second integer: ");
            scanf("%d", &int2);
            
            if (int2 != 0) {
                intResult = modulus(int1, int2);
                printf("%d %% %d = %d\n", int1, int2, intResult);
            } else {
                printf("Error: Modulus by zero!\n");
            }
            break;
            
        default:
            printf("Invalid choice!\n");
    }
}

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

int modulus(int a, int b) {
    return a % b;
} 