#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[MAX_NAME];
    float gpa;
    char grade;
} Student;

void addStudent(FILE *file);
void viewAllStudents(FILE *file);
void searchStudent(FILE *file);
void deleteStudent(FILE *file);
void updateStudent(FILE *file);
void displayMenu();

int main() {
    FILE *file;
    int choice;
    
    // Open file in binary read/write mode
    file = fopen("students.dat", "rb+");
    if (file == NULL) {
        file = fopen("students.dat", "wb+");
        if (file == NULL) {
            printf("Error creating file!\n");
            return 1;
        }
    }
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent(file);
                break;
            case 2:
                viewAllStudents(file);
                break;
            case 3:
                searchStudent(file);
                break;
            case 4:
                updateStudent(file);
                break;
            case 5:
                deleteStudent(file);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    fclose(file);
    return 0;
}

void displayMenu() {
    printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
    printf("1. Add Student\n");
    printf("2. View All Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Exit\n");
    printf("========================================\n");
}

void addStudent(FILE *file) {
    Student student;
    
    printf("\nEnter Student ID: ");
    scanf("%d", &student.id);
    
    printf("Enter Student Name: ");
    getchar(); // Clear buffer
    fgets(student.name, MAX_NAME, stdin);
    student.name[strcspn(student.name, "\n")] = 0; // Remove newline
    
    printf("Enter GPA: ");
    scanf("%f", &student.gpa);
    
    // Calculate grade based on GPA
    if (student.gpa >= 3.7) student.grade = 'A';
    else if (student.gpa >= 3.3) student.grade = 'B';
    else if (student.gpa >= 3.0) student.grade = 'C';
    else if (student.gpa >= 2.0) student.grade = 'D';
    else student.grade = 'F';
    
    // Write to file
    fseek(file, 0, SEEK_END);
    fwrite(&student, sizeof(Student), 1, file);
    
    printf("Student added successfully!\n");
}

void viewAllStudents(FILE *file) {
    Student student;
    int count = 0;
    
    rewind(file);
    
    printf("\n%-10s %-20s %-10s %-10s\n", "ID", "Name", "GPA", "Grade");
    printf("------------------------------------------------\n");
    
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        printf("%-10d %-20s %-10.2f %-10c\n", 
               student.id, student.name, student.gpa, student.grade);
        count++;
    }
    
    if (count == 0) {
        printf("No students found!\n");
    } else {
        printf("\nTotal students: %d\n", count);
    }
}

void searchStudent(FILE *file) {
    Student student;
    int searchId, found = 0;
    
    printf("Enter Student ID to search: ");
    scanf("%d", &searchId);
    
    rewind(file);
    
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.id == searchId) {
            printf("\nStudent Found:\n");
            printf("ID: %d\n", student.id);
            printf("Name: %s\n", student.name);
            printf("GPA: %.2f\n", student.gpa);
            printf("Grade: %c\n", student.grade);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student not found!\n");
    }
}

void updateStudent(FILE *file) {
    Student student;
    int searchId, found = 0;
    long position;
    
    printf("Enter Student ID to update: ");
    scanf("%d", &searchId);
    
    rewind(file);
    
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.id == searchId) {
            position = ftell(file) - sizeof(Student);
            fseek(file, position, SEEK_SET);
            
            printf("Enter new name: ");
            getchar();
            fgets(student.name, MAX_NAME, stdin);
            student.name[strcspn(student.name, "\n")] = 0;
            
            printf("Enter new GPA: ");
            scanf("%f", &student.gpa);
            
            // Recalculate grade
            if (student.gpa >= 3.7) student.grade = 'A';
            else if (student.gpa >= 3.3) student.grade = 'B';
            else if (student.gpa >= 3.0) student.grade = 'C';
            else if (student.gpa >= 2.0) student.grade = 'D';
            else student.grade = 'F';
            
            fwrite(&student, sizeof(Student), 1, file);
            printf("Student updated successfully!\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student not found!\n");
    }
}

void deleteStudent(FILE *file) {
    FILE *tempFile;
    Student student;
    int searchId, found = 0;
    
    printf("Enter Student ID to delete: ");
    scanf("%d", &searchId);
    
    tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("Error creating temporary file!\n");
        return;
    }
    
    rewind(file);
    
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.id != searchId) {
            fwrite(&student, sizeof(Student), 1, tempFile);
        } else {
            found = 1;
        }
    }
    
    fclose(tempFile);
    fclose(file);
    
    remove("students.dat");
    rename("temp.dat", "students.dat");
    
    file = fopen("students.dat", "rb+");
    
    if (found) {
        printf("Student deleted successfully!\n");
    } else {
        printf("Student not found!\n");
    }
} 