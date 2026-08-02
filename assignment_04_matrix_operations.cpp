// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//
// Author: Portia Affusah

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <iostream>
#include <iomanip>

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const std::string& name = "Matrix") {
    std::cout << "\n--- Entering elements for " << name << " (" << rows << "x" << cols << ") ---\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter element [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(6) << matrix[i][j];
        }
        std::cout << "\n";
    }
}


void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int dest[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            dest[j][i] = src[i][j];
        }
    }
}


void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], 
                 int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], 
                      int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0; // Initialize cell accumulator
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {

    std::cout << "========================================\n";
    std::cout << "PART A: Matrix Transposition\n";
    std::cout << "========================================\n";
    int rowsA, colsA;
    std::cout << "Enter number of rows: ";
    std::cin >> rowsA;
    std::cout << "Enter number of columns: ";
    std::cin >> colsA;

    int matrixA[MAX_SIZE][MAX_SIZE];
    readMatrix(matrixA, rowsA, colsA, "Matrix A");

    int transposeA[MAX_SIZE][MAX_SIZE];
    transposeMatrix(matrixA, transposeA, rowsA, colsA);

    std::cout << "\nOriginal Matrix:\n";
    printMatrix(matrixA, rowsA, colsA);

    std::cout << "\nTransposed Matrix:\n";
    printMatrix(transposeA, colsA, rowsA);

    std::cout << "\n========================================\n";
    std::cout << "PART B: Matrix Addition\n";
    std::cout << "========================================\n";
    std::cout << "Enter matrix B with matching dimensions (" << rowsA << "x" << colsA << "):\n";
    
    int matrixB[MAX_SIZE][MAX_SIZE];
    readMatrix(matrixB, rowsA, colsA, "Matrix B");

    int sumMatrix[MAX_SIZE][MAX_SIZE];
    addMatrices(matrixA, matrixB, sumMatrix, rowsA, colsA);

    std::cout << "\nMatrix A + Matrix B:\n";
    printMatrix(sumMatrix, rowsA, colsA);

    // -------------------------------------------------------------------------
    // PART C DEMO: Multiplication
    // -------------------------------------------------------------------------
    std::cout << "\n========================================\n";
    std::cout << "PART C: Matrix Multiplication\n";
    std::cout << "========================================\n";
    int colsC;
    std::cout << "For A x C, Matrix A is (" << rowsA << "x" << colsA << ").\n";
    std::cout << "Matrix C must have " << colsA << " rows.\n";
    std::cout << "Enter number of columns for Matrix C: ";
    std::cin >> colsC;

    int matrixC[MAX_SIZE][MAX_SIZE];
    readMatrix(matrixC, colsA, colsC, "Matrix C");

    int productMatrix[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(matrixA, matrixC, productMatrix, rowsA, colsA, colsC);

    std::cout << "\nMatrix A x Matrix C:\n";
    printMatrix(productMatrix, rowsA, colsC);

    return 0;
}