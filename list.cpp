#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task class (Encapsulation)
class Task
{
private:
    string taskName;

public:
    Task(string name) : taskName(name) {} // Constructor

    string getTaskName() const { return taskName; }    // Getter
    void setTaskName(string name) { taskName = name; } // Setter
};

// ToDoList class (Abstraction, Encapsulation)
class ToDoList
{
private:
    vector<Task *> tasks; // Using a vector of pointers to store tasks

public:
    void addTask(string taskName)
    {
        Task *newTask = new Task(taskName); // Using pointers (dynamic memory allocation)
        tasks.push_back(newTask);
        cout << "------------------------------------\n";
        cout << "Todo added successfully.\n";
        cout << "------------------------------------\n";
    }

    void editTask(int index)
    {
        if (index >= 0 && index < tasks.size())
        {
            string newTitle;
            cout << "------------------------------------\n";
            cout << "Enter new task: ";
            cin.ignore();
            getline(cin, newTitle);
            tasks[index]->setTaskName(newTitle); // Using the pointer to access the object
            cout << "------------------------------------\n";
            cout << "Todo edited successfully.\n";
            cout << "------------------------------------\n";
        }
        else
        {
            cout << "Invalid index.\n";
            cout << "------------------------------------\n";
        }
    }

    void deleteTask(int index)
    {
        if (index >= 0 && index < tasks.size())
        {
            delete tasks[index]; // Deleting the dynamically allocated object
            tasks.erase(tasks.begin() + index);
            cout << "------------------------------------\n";
            cout << "Todo deleted successfully.\n";
            cout << "------------------------------------\n";
        }
        else
        {
            cout << "Invalid index.\n";
            cout << "------------------------------------\n";
        }
    }

    void displayList() const
    {
        if (tasks.empty())
        {
            cout << "------------------------------------\n";
            cout << "Todo list is empty.\n";
            cout << "------------------------------------\n";
        }
        else
        {
            cout << "Todo List:\n";
            for (int i = 0; i < tasks.size(); i++)
            {
                cout << i << ". Title: " << tasks[i]->getTaskName() << "\n"; // Using the pointer to access the object
            }
            cout << "------------------------------------\n";
        }
    }

    ~ToDoList()
    { // Destructor
        for (Task *task : tasks)
        {
            delete task; // Deleting dynamically allocated objects
        }
    }
};

int main()
{
    ToDoList todoList; // Object creation

    while (true)
    {
        cout << "1. Add a task\n2. Edit a task\n3. Delete a task\n4. Display List\n5. Exit\nEnter your choice: ";
        int choice;
        cin >> choice;
        cout << "------------------------------------\n";

        switch (choice)
        {
        case 1:
        {
            string taskName;
            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, taskName);
            todoList.addTask(taskName);
            break;
        }
        case 2:
        {
            int index;
            cout << "------------------------------------\n";
            cout << "Enter the index of the todo to edit: ";
            cin >> index;
            todoList.editTask(index);
            break;
        }
        case 3:
        {
            int index;
            cout << "------------------------------------\n";
            cout << "Enter the index of the todo to delete: ";
            cin >> index;
            todoList.deleteTask(index);
            break;
        }
        case 4:
            todoList.displayList();
            break;
        case 5:
            return 0;
        default:
            cout << "------------------------------------\n";
            cout << "Invalid choice. Try again.\n";
            cout << "------------------------------------\n";
        }
    }

    return 0;
}