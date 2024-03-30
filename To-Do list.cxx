#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Task {
public:
    Task(string description) : description_(move(description)), completed_(false) {}

    void toggleCompleted() {
        completed_ = !completed_;
    }

    friend ostream& operator<<(ostream& os, const Task& task);

private:
    string description_;
    bool completed_;
};

ostream& operator<<(ostream& os, const Task& task) {
    os << task.description_ << " (";
    os << (task.completed_ ? "completed" : "pending");
    os << ")";
    return os;
}

class ToDoList {
public:
    void addTask(const string& description) {
        tasks_.emplace_back(description);
        cout << "Task \"" << description << "\" has been added.\n";
    }

    void viewTasks() {
        cout << "Your tasks:\n";
        for (size_t i = 0; i < tasks_.size(); ++i) {
            cout << i + 1 << ". " << tasks_[i] << '\n';
        }
    }

    void markTaskCompleted(size_t taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks_.size()) {
            cout << "Invalid task index.\n";
            return;
        }
        tasks_[taskIndex - 1].toggleCompleted();
        cout << "Task " << taskIndex << " has been marked as completed.\n";
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks_.size()) {
            cout << "Invalid task index.\n";
            return;
        }
        tasks_.erase(tasks_.begin() + taskIndex - 1);
        cout << "Task " << taskIndex << " has been removed.\n";
    }

private:
    vector<Task> tasks_;
};

int main() {
    ToDoList toDoList;

    while (true) {
        cout << "1. Add task\n2. View tasks\n3. Mark task as completed\n4. Remove task\n5. Exit\n";
        int action;
        cin >> action;

        switch (action) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                size_t taskToComplete;
                cout << "Enter task number to mark as completed: ";
                cin >> taskToComplete;
                toDoList.markTaskCompleted(taskToComplete);
                break;
            }
            case 4: {
                size_t taskToRemove;
                cout << "Enter task number to remove: ";
                cin >> taskToRemove;
                toDoList.removeTask(taskToRemove);
                break;
            }
            case 5:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid action. Try again.\n";
        }
    }

    return 0;
}