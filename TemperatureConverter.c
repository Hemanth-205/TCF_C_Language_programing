#include <stdio.h>

// Function prototypes
void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);
void convertTemperature();

int main() {
    int choice;
    
    printf("=== TEMPERATURE CONVERTER ===\n");
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                convertTemperature();
                break;
            case 2:
                printf("Thank you for using Temperature Converter!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 2);
    
    return 0;
}

void displayMenu() {
    printf("\n1. Convert Temperature\n");
    printf("2. Exit\n");
    printf("========================\n");
}

void convertTemperature() {
    int choice;
    float temperature, result;
    
    printf("\nSelect conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter temperature: ");
    scanf("%f", &temperature);
    
    switch (choice) {
        case 1:
            result = celsiusToFahrenheit(temperature);
            printf("%.2f°C = %.2f°F\n", temperature, result);
            break;
        case 2:
            result = fahrenheitToCelsius(temperature);
            printf("%.2f°F = %.2f°C\n", temperature, result);
            break;
        case 3:
            result = celsiusToKelvin(temperature);
            printf("%.2f°C = %.2f K\n", temperature, result);
            break;
        case 4:
            result = kelvinToCelsius(temperature);
            printf("%.2f K = %.2f°C\n", temperature, result);
            break;
        case 5:
            result = fahrenheitToKelvin(temperature);
            printf("%.2f°F = %.2f K\n", temperature, result);
            break;
        case 6:
            result = kelvinToFahrenheit(temperature);
            printf("%.2f K = %.2f°F\n", temperature, result);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
} 