// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//
// Author: Portia Affusah

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;


void displayMenu();
void addTask(std::vector<std::string>& tasks);
void viewTasks(const std::vector<std::string>& tasks);
void deleteTask(std::vector<std::string>& tasks);

int main() {
    std::vector<std::string> tasks;
    int choice = 0;

    while (choice != 4) {
        displayMenu();
        std::cout << "Enter your choice (1-4): ";

        // Check if user entered a valid integer choice
        if (!(std::cin >> choice)) {
            std::cout << "\n[Error] Invalid input. Please enter a number from 1 to 4.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                std::cout << "\nGoodbye! Have a productive day!\n";
                break;
            default:
                std::cout << "\n[Error] Invalid choice. Please select an option between 1 and 4.\n";
                break;
        }
    }

    return 0;
}

void displayMenu() {
    std::cout << "\n============================\n";
    std::cout << "        TO-DO LIST MENU      \n";
    std::cout << "============================\n";
    std::cout << "1. Add task\n";
    std::cout << "2. View tasks\n";
    std::cout << "3. Delete task\n";
    std::cout << "4. Quit\n";
}

void addTask(std::vector<std::string>& tasks) {
    // Clear newline residue left in input buffer from previous std::cin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string taskDescription;
    std::cout << "\nEnter task: ";
    std::getline(std::cin, taskDescription);

    if (taskDescription.empty()) {
        std::cout << "[Error] Task description cannot be empty.\n";
        return;
    }

    tasks.push_back(taskDescription);
    std::cout << "Task added: \"" << taskDescription << "\"\n";
}

void viewTasks(const std::vector<std::string>& tasks) {
    std::cout << "\nYour Tasks:\n";

    if (tasks.empty()) {
        std::cout << "  (No tasks found. Your list is empty!)\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << "  " << (i + 1) << ". " << tasks[i] << "\n";
    }
}

void deleteTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "\nYour task list is empty. Nothing to delete!\n";
        return;
    }

    viewTasks(tasks);

    int taskNum;
    std::cout << "\nEnter task number to delete: ";

    if (!(std::cin >> taskNum)) {
        std::cout << "[Error] Invalid input. Please enter a valid number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    int index = taskNum - 1;


    if (index >= 0 && index < static_cast<int>(tasks.size())) {
        std::string removedTask = tasks[index];
        tasks.erase(tasks.begin() + index);
        std::cout << "Task \"" << removedTask << "\" has been removed.\n";
    } else {
        std::cout << "[Error] Invalid task number. Please enter a number between 1 and " 
                  << tasks.size() << ".\n";
    }
}