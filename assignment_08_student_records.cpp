// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//
// Author: Portia Affusah

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


struct Student {
    std::string name;
    int id;
    std::vector<double> scores;
};

double calculateAverage(const std::vector<double>& scores) {
    if (scores.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

void displayMenu();
void addStudent(std::vector<Student>& students);
void displayAllStudents(const std::vector<Student>& students);
void findAndCalculateAverage(const std::vector<Student>& students);

int main() {
    std::vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        displayMenu();
        std::cout << "Enter your choice (1-4): ";

        if (!(std::cin >> choice)) {
            std::cout << "\n[Error] Invalid input. Please enter a number from 1 to 4.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                findAndCalculateAverage(students);
                break;
            case 4:
                std::cout << "\nGoodbye!\n";
                break;
            default:
                std::cout << "\n[Error] Invalid option. Please select between 1 and 4.\n";
                break;
        }
    }

    return 0;
}

void displayMenu() {
    std::cout << "\n================================\n";
    std::cout << "   STUDENT RECORD SYSTEM MENU   \n";
    std::cout << "================================\n";
    std::cout << "1. Add student\n";
    std::cout << "2. Display all students\n";
    std::cout << "3. Calculate average score\n";
    std::cout << "4. Quit\n";
}

void addStudent(std::vector<Student>& students) {
    // Clear newline character left in input buffer from previous std::cin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Student newStudent;

    std::cout << "\nStudent name: ";
    std::getline(std::cin, newStudent.name);

    std::cout << "Student ID: ";
    while (!(std::cin >> newStudent.id)) {
        std::cout << "[Error] Invalid ID. Please enter a numerical ID: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int numScores = 0;
    std::cout << "How many scores? ";
    while (!(std::cin >> numScores) || numScores < 0) {
        std::cout << "[Error] Please enter a non-negative integer for number of scores: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (int i = 0; i < numScores; ++i) {
        double score;
        std::cout << "Enter score " << (i + 1) << ": ";
        while (!(std::cin >> score) || score < 0) {
            std::cout << "[Error] Please enter a valid non-negative score: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        newStudent.scores.push_back(score);
    }

    students.push_back(newStudent);
    std::cout << "Student \"" << newStudent.name << "\" added successfully.\n";
}

void displayAllStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "\nNo students have been added yet.\n";
        return;
    }

    std::cout << "\n-------------------------------------------------------------------\n";
    std::cout << std::left << std::setw(20) << "Name"
              << std::setw(12) << "ID"
              << std::setw(25) << "Scores"
              << std::setw(10) << "Average" << "\n";
    std::cout << "-------------------------------------------------------------------\n";

    std::cout << std::fixed << std::setprecision(2);

    for (const auto& student : students) {
        // Build scores string
        std::string scoresStr = "[";
        for (size_t i = 0; i < student.scores.size(); ++i) {
            // Convert score to string formatted to 2 decimals
            std::ostringstream ss;
            ss << std::fixed << std::setprecision(1) << student.scores[i];
            scoresStr += ss.str();
            if (i < student.scores.size() - 1) {
                scoresStr += ", ";
            }
        }
        scoresStr += "]";

        double avg = calculateAverage(student.scores);

        std::cout << std::left << std::setw(20) << student.name
                  << std::setw(12) << student.id
                  << std::setw(25) << scoresStr
                  << std::setw(10) << avg << "\n";
    }
    std::cout << "-------------------------------------------------------------------\n";
}
void findAndCalculateAverage(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "\nNo students available in the system.\n";
        return;
    }

    int searchId;
    std::cout << "\nEnter student ID: ";
    if (!(std::cin >> searchId)) {
        std::cout << "[Error] Invalid input. ID must be an integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    for (const auto& student : students) {
        if (student.id == searchId) {
            double avg = calculateAverage(student.scores);
            std::cout << std::fixed << std::setprecision(2);
            std::cout << student.name << "'s average score: " << avg << "\n";
            return;
        }
    }

    std::cout << "[Error] Student with ID " << searchId << " was not found.\n";
}