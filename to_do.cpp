#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ToDoList {
private:
    vector<string> tasks;

public:
    void addTask(const string& task) {
        tasks.push_back(task);
        cout << "Task added Successfully!!" << endl;
    }

    void deleteTask(int index) {
        tasks.erase(tasks.begin() + index);
        cout << "Task deleted Successfully!!" << endl;
    }

    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index] = tasks[index] + " [Completed]";
            cout << "Task marked as completed: " << tasks[index] << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void markTaskAsPending(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index] = tasks[index] + " [Pending]";
            cout << "Task marked as Pending: " << tasks[index] << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void viewTaskIndex() {
        cout << "----- Task and their Index -----" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << "Task name: " << tasks[i] << "\t\t index: "<< i<< endl;
        }
        cout << "--------------------------------" << endl;
    }

    void viewTasks() {
        cout << "----- To-Do List -----" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
        cout << "-----------------------" << endl;
    }
};

int main() {
    ToDoList toDoList;
    int choice;

    do {
        cout << "\n\t\t #########################################" << endl;
        cout << "\t\t\tTo-Do List Application\n";
        cout << "\t\t ------------------------------------------" << endl;
        cout << "\t\t\t 1. Add Task\n";
        cout << "\t\t\t 2. Mark Task as Completed\n";
        cout << "\t\t\t 3. Mark Task as Pending\n";
        cout << "\t\t\t 4. Delete Task\n";
        cout << "\t\t\t 5. View Tasks\n";
        cout << "\t\t\t 6. Exit\n";
        cout << "\t\t ------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter your task name: ";
                // cin.ignore();
                // getline(cin, task);
                cin >> task;
                toDoList.addTask(task);
                break;
            }
            case 2: {
                toDoList.viewTaskIndex();
                int index;
                cout << "\nEnter the index of the task to mark as completed: ";
                cin >> index;
                toDoList.markTaskAsCompleted(index); // Adjust for 0-based indexing
                break;
            }
            case 3: {
                toDoList.viewTaskIndex();
                int index;
                cout << "\nEnter the index of the task to mark as Pending: ";
                cin >> index;
                toDoList.markTaskAsPending(index); // Adjust for 0-based indexing
                break;
            }
            case 4:
                toDoList.viewTaskIndex();
                int index;
                cout << "\nEnter the index of the task you want to delete: ";
                cin >> index;
                toDoList.deleteTask(index);
                break;
            case 5:
                toDoList.viewTasks();
                break;
            case 6:
                cout << "Thank you for visiting TODO App. Have a nice day!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
