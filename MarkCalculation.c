#include <stdio.h>

// Function prototypes
void inputMarks(int marks[], int n);
int calculateTotal(int marks[], int n);
float calculatePercentage(int total, int n);
char calculateGrade(float percentage);
void displayResult(int marks[], int n, int total, float percentage, char grade);
void displayMenu();

int main() {
    int marks[5], total, choice;
    float percentage;
    char grade;
    
    printf("=== STUDENT MARK CALCULATION SYSTEM ===\n");
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                inputMarks(marks, 5);
                break;
            case 2:
                total = calculateTotal(marks, 5);
                printf("Total marks: %d\n", total);
                break;
            case 3:
                total = calculateTotal(marks, 5);
                percentage = calculatePercentage(total, 5);
                printf("Percentage: %.2f%%\n", percentage);
                break;
            case 4:
                total = calculateTotal(marks, 5);
                percentage = calculatePercentage(total, 5);
                grade = calculateGrade(percentage);
                printf("Grade: %c\n", grade);
                break;
            case 5:
                total = calculateTotal(marks, 5);
                percentage = calculatePercentage(total, 5);
                grade = calculateGrade(percentage);
                displayResult(marks, 5, total, percentage, grade);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    
    return 0;
}

void displayMenu() {
    printf("\n1. Input Marks\n");
    printf("2. Calculate Total\n");
    printf("3. Calculate Percentage\n");
    printf("4. Calculate Grade\n");
    printf("5. Display Complete Result\n");
    printf("6. Exit\n");
    printf("=====================================\n");
}

void inputMarks(int marks[], int n) {
    printf("Enter marks for %d subjects:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[i]);
        
        // Validate marks
        if (marks[i] < 0 || marks[i] > 100) {
            printf("Invalid marks! Please enter marks between 0-100.\n");
            i--; // Retry for this subject
        }
    }
    printf("Marks entered successfully!\n");
}

int calculateTotal(int marks[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += marks[i];
    }
    return total;
}

float calculatePercentage(int total, int n) {
    return (float)total / (n * 100) * 100;
}

char calculateGrade(float percentage) {
    if (percentage >= 90) return 'A';
    else if (percentage >= 80) return 'B';
    else if (percentage >= 70) return 'C';
    else if (percentage >= 60) return 'D';
    else if (percentage >= 50) return 'E';
    else return 'F';
}

void displayResult(int marks[], int n, int total, float percentage, char grade) {
    printf("\n=== STUDENT RESULT ===\n");
    printf("Subject-wise marks:\n");
    for (int i = 0; i < n; i++) {
        printf("Subject %d: %d\n", i + 1, marks[i]);
    }
    printf("Total marks: %d\n", total);
    printf("Percentage: %.2f%%\n", percentage);
    printf("Grade: %c\n", grade);
    
    if (grade == 'A') printf("Excellent!\n");
    else if (grade == 'B') printf("Good!\n");
    else if (grade == 'C') printf("Average!\n");
    else if (grade == 'D') printf("Below Average!\n");
    else if (grade == 'E') printf("Poor!\n");
    else printf("Fail!\n");
} 