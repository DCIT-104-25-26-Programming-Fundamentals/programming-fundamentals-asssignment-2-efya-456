// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//
// Author: Portia Affusah

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>

void printFibonacciTerms(int n) {
    if (n <= 0) {
        std::cout << "Error: N must be a positive integer.\n";
        return;
    }

    std::cout << "Fibonacci sequence: ";

    long long first = 0, second = 1;

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            std::cout << first;
        } else if (i == 1) {
            std::cout << " " << second;
        } else {
            long long next = first + second;
            std::cout << " " << next;
            first = second;
            second = next;
        }
    }
    std::cout << "\n";
}

bool isFibonacci(long long target) {
    if (target < 0) {
        return false;
    }

    long long first = 0, second = 1;
    if (target == first || target == second) {
        return true;
    }

    long long next = first + second;
    while (next <= target) {
        if (next == target) {
            return true;
        }
        first = second;
        second = next;
        next = first + second;
    }

    return false;
}

int main() {
    std::cout << "========================================\n";
    std::cout << "PART A: Print First N Terms\n";
    std::cout << "========================================\n";
    
    int n;
    std::cout << "How many terms? ";
    std::cin >> n;

    printFibonacciTerms(n);

    std::cout << "\n========================================\n";
    std::cout << "PART B: Check Fibonacci Number\n";
    std::cout << "========================================\n";

    long long numToCheck;
    std::cout << "Enter a number to check: ";
    std::cin >> numToCheck;

    if (isFibonacci(numToCheck)) {
        std::cout << numToCheck << " is a Fibonacci number.\n";
    } else {
        std::cout << numToCheck << " is NOT a Fibonacci number.\n";
    }

    return 0;
}