#include <stdio.h>

#define MAX 10

// Function for matrix addition
void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function for matrix multiplication
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function for transpose
void transposeMatrix(int A[MAX][MAX], int result[MAX][MAX], int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            result[j][i] = A[i][j];
        }
    }
}

// Function to print matrix
void printMatrix(int A[MAX][MAX], int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;

    // Input matrix A
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    // Input matrix B
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Matrix B:\n");
    for(int i = 0; i < r2; i++)
        for(int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    // Matrix Addition
    if(r1 == r2 && c1 == c2) {
        addMatrix(A, B, result, r1, c1);
        printf("\nMatrix Addition Result:\n");
        printMatrix(result, r1, c1);
    } else {
        printf("\nMatrix Addition not possible!\n");
    }

    // Matrix Multiplication
    if(c1 == r2) {
        multiplyMatrix(A, B, result, r1, c1, c2);
        printf("\nMatrix Multiplication Result:\n");
        printMatrix(result, r1, c2);
    } else {
        printf("\nMatrix Multiplication not possible!\n");
    }

    // Transpose of Matrix A
    transposeMatrix(A, result, r1, c1);
    printf("\nTranspose of Matrix A:\n");
    printMatrix(result, c1, r1);

    return 0;
}