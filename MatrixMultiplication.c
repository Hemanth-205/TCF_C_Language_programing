#include <stdio.h>
#include <stdlib.h>

// Function to create a matrix dynamically
int** createMatrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        return NULL;
    }
    
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

// Function to input elements into a matrix
int inputMatrix(int **matrix, int rows, int cols) {
    if (matrix == NULL || rows <= 0 || cols <= 0) {
        return 0;
    }
    
    printf("Enter elements (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter a valid integer.\n");
                // Clear input buffer
                while (getchar() != '\n');
                return 0;
            }
        }
    }
    return 1;
}

// Function to multiply two matrices
int** multiplyMatrices(int **A, int **B, int r1, int c1, int c2) {
    if (A == NULL || B == NULL || r1 <= 0 || c1 <= 0 || c2 <= 0) {
        return NULL;
    }
    
    int **C = createMatrix(r1, c2);
    if (C == NULL) {
        return NULL;
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Function to display a matrix
void displayMatrix(int **matrix, int rows, int cols) {
    if (matrix == NULL || rows <= 0 || cols <= 0) {
        printf("Invalid matrix to display.\n");
        return;
    }
    
    printf("\nMatrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free allocated memory
void freeMatrix(int **matrix, int rows) {
    if (matrix == NULL || rows <= 0) {
        return;
    }
    
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int r1, c1, r2, c2;

    // Input matrix dimensions
    printf("Enter rows and columns for Matrix A: ");
    if (scanf("%d %d", &r1, &c1) != 2 || r1 <= 0 || c1 <= 0) {
        printf("Invalid input for Matrix A dimensions. Please enter positive integers.\n");
        return 1;
    }

    printf("Enter rows and columns for Matrix B: ");
    if (scanf("%d %d", &r2, &c2) != 2 || r2 <= 0 || c2 <= 0) {
        printf("Invalid input for Matrix B dimensions. Please enter positive integers.\n");
        return 1;
    }

    // Check multiplication condition
    if (c1 != r2) {
        printf("Matrix multiplication not possible. Number of columns in A (%d) must equal number of rows in B (%d).\n", c1, r2);
        return 1;
    }

    // Create matrices
    int **A = createMatrix(r1, c1);
    if (A == NULL) {
        printf("Memory allocation failed for Matrix A.\n");
        return 1;
    }
    
    int **B = createMatrix(r2, c2);
    if (B == NULL) {
        printf("Memory allocation failed for Matrix B.\n");
        freeMatrix(A, r1);
        return 1;
    }

    // Input matrices
    printf("\nInput Matrix A:\n");
    if (!inputMatrix(A, r1, c1)) {
        printf("Error reading Matrix A.\n");
        freeMatrix(A, r1);
        freeMatrix(B, r2);
        return 1;
    }

    printf("\nInput Matrix B:\n");
    if (!inputMatrix(B, r2, c2)) {
        printf("Error reading Matrix B.\n");
        freeMatrix(A, r1);
        freeMatrix(B, r2);
        return 1;
    }

    // Multiply matrices
    int **C = multiplyMatrices(A, B, r1, c1, c2);
    if (C == NULL) {
        printf("Memory allocation failed for result matrix.\n");
        freeMatrix(A, r1);
        freeMatrix(B, r2);
        return 1;
    }

    // Display result
    printf("\nMatrix A:");
    displayMatrix(A, r1, c1);
    
    printf("\nMatrix B:");
    displayMatrix(B, r2, c2);

    printf("\nResultant Matrix C (A x B):");
    displayMatrix(C, r1, c2);

    // Free memory
    freeMatrix(A, r1);
    freeMatrix(B, r2);
    freeMatrix(C, r1);

    return 0;
}
