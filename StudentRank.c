#include <stdio.h>

// Define the structure
struct Student {
    int id;
    char name[50];
    int marks[5];
    float average;
};

// Function to input student details
void inputStudents(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &s[i].id);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);
        printf("Enter 5 subject marks:\n");
        for (int j = 0; j < 5; j++) {
            printf("Mark %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
        }
    }
}

// Function to calculate average for each student
void calculateAverage(struct Student *s) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += s->marks[i];
    }
    s->average = total / 5.0;
}

// Function to display the topper
void displayTopper(struct Student s[], int n) {
    int topperIndex = 0;
    for (int i = 1; i < n; i++) {
        if (s[i].average > s[topperIndex].average) {
            topperIndex = i;
        }
    }
    printf("\nTopper Details:\n");
    printf("ID: %d\n", s[topperIndex].id);
    printf("Name: %s\n", s[topperIndex].name);
    printf("Marks: ");
    for (int j = 0; j < 5; j++) {
        printf("%d ", s[topperIndex].marks[j]);
    }
    printf("\nAverage: %.2f\n", s[topperIndex].average);
}

int main() {
    int n = 5;  // Number of students
    struct Student students[n];

    // Step 1: Input details
    inputStudents(students, n);

    // Step 2: Calculate average for each student
    for (int i = 0; i < n; i++) {
        calculateAverage(&students[i]);
    }

    // Step 3: Display topper
    displayTopper(students, n);

    return 0;
}
