// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//
// Author: Portia Affusah

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>
#include <iomanip>

void printSingleTable(int num) {
    if (num <= 0) {
        std::cout << "Error: Please enter a positive integer.\n";
        return;
    }

    std::cout << "\nMultiplication Table for " << num << ":\n";
    for (int i = 1; i <= 12; ++i) {
        std::cout << std::setw(2) << num << "  x  " 
                  << std::setw(2) << i << "  =  " 
                  << std::setw(3) << num * i << "\n";
    }
}

void printTablesUpToN(int n) {
    if (n <= 0) {
        std::cout << "Error: N must be a positive integer.\n";
        return;
    }

    for (int current = 1; current <= n; ++current) {
        printSingleTable(current);
        
        if (current < n) {
            std::cout << "---------------------------\n";
        }
    }
}

int main() {
    std::cout << "========================================\n";
    std::cout << "PART A: Single Multiplication Table\n";
    std::cout << "========================================\n";
    
    int singleNum;
    std::cout << "Enter a number: ";
    std::cin >> singleNum;

    if (singleNum <= 0) {
        std::cout << "Error: Invalid input. Number must be positive.\n";
    } else {
        printSingleTable(singleNum);
    }

    std::cout << "\n========================================\n";
    std::cout << "PART B: Multiplication Tables from 1 to N\n";
    std::cout << "========================================\n";

    int maxN;
    std::cout << "Enter N: ";
    std::cin >> maxN;

    if (maxN <= 0) {
        std::cout << "Error: Invalid input. N must be a positive integer.\n";
    } else {
        printTablesUpToN(maxN);
    }

    return 0;
}