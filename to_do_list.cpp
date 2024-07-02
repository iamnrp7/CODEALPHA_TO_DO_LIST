#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct to represent a task
struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

// Function prototypes
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskAsCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);
void displayMenu();

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();  // Ignore newline character after choice

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}

void displayMenu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter task description: ";
    getline(cin, description);
    tasks.push_back(Task(description));
    cout << "Task added." << endl;
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
    } else {
        cout << "\nTasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " [" 
                 << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
        }
    }
}

void markTaskAsCompleted(vector<Task>& tasks) {
    int taskNum;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNum;
    if (taskNum > 0 && taskNum <= static_cast<int>(tasks.size())) {
        tasks[taskNum - 1].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void removeTask(vector<Task>& tasks) {
    int taskNum;
    cout << "Enter task number to remove: ";
    cin >> taskNum;
    if (taskNum > 0 && taskNum <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + taskNum - 1);
        cout << "Task removed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}
