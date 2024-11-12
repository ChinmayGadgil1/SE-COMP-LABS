#include <bits/stdc++.h>
using namespace std;
class Todo
{
    string text;
    bool isCompleted;

public:
    Todo()
    {
        text = "";
        isCompleted = false;
    }
    Todo(string t, bool c = false)
    {
        text = t;
        isCompleted = c;
    }
    void create()
    {
        cout << "\nEnter todo: ";
        cin.ignore();
        getline(cin, text);
    }
    void writeToFile()
    {
        fstream out;
        out.open("expt8.txt", ios::app);
        if (!out)
        {
            cout << "Error opening file" << endl;
            return;
        }
        out << text << "\n";
        out << (isCompleted ? "Completed " : "Not Completed ") << "\n\n";
        out.close();
    }
    friend void deleteTodo(int n);
    friend void editTodo(int n);
    friend void markAsCompleted(int n);
};
void deleteTodo(int n)
{
    ifstream inFile("expt8.txt");
    if (!inFile)
    {
        cout << "Error opening file" << endl;
        return;
    }
    vector<string> todos;
    string line;
    int count = 0;
    while (getline(inFile, line))
    {
        if (line.empty())
            continue;
        if (++count == n)
        {
            getline(inFile, line);
            continue;
        }
        todos.push_back(line);
        getline(inFile, line);
        todos.push_back(line);
        todos.push_back("");
    }
    inFile.close();
    ofstream outFile("expt8.txt");
    if (!outFile)
    {
        cout << "Error opening file" << endl;
        return;
    }
    for (auto &todo : todos)
    {
        outFile << todo << "\n";
    }
    outFile.close();
}
void editTodo(int n)
{
    ifstream inFile("expt8.txt");
    if (!inFile)
    {
        cout << "Error opening file" << endl;
        return;
    }
    vector<string> todos;
    string line;
    int count = 0;
    while (getline(inFile, line))
    {
        if (line.empty())
            continue;
        if (++count == n)
        {
            cout << "Enter new todo: ";
            cin.ignore();
            getline(cin, line);
        }
        todos.push_back(line);
        getline(inFile, line);
        todos.push_back(line);
        todos.push_back("");
    }
    inFile.close();
    ofstream outFile("expt8.txt");
    if (!outFile)
    {
        cout << "Error opening file" << endl;
        return;
    }
    for (const auto &todo : todos)
    {
        outFile << todo << "\n";
    }
    outFile.close();
}
void markAsCompleted(int n)
{
    ifstream inFile("expt8.txt");
    if (!inFile)
    {
        cout << "Error opening file" << endl;
        return;
    }
    vector<string> todos;
    string line;
    int count = 0;
    while (getline(inFile, line))
    {
        if (line.empty())
            continue;
        if (++count == n)
        {
            todos.push_back(line);
            todos.push_back("Completed ");
            getline(inFile, line);
        }
        else
        {
            todos.push_back(line);
            getline(inFile, line);
            todos.push_back(line);
        }
        todos.push_back("");
    }
    inFile.close();
    ofstream outFile("expt8.txt");
    if (!outFile)
    {
        cout << "Error opening file" << endl;
        return;
    }
    for (const auto &todo : todos)
    {
        outFile << todo << "\n";
    }
    outFile.close();
}
int main()
{
    int choice;
    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1) Enter todo\n2) Delete todo\n3) Edit todo\n4) Mark todo as completed\n5) Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            Todo t;
            t.create();
            t.writeToFile();
        }
        else if (choice == 2)
        {
            int n;
            cout << "Enter no of todo to delete:";
                    cin >>n;
            deleteTodo(n);
        }
        else if (choice == 3)
        {
            int n;
            cout << "Enter no of todo to edit: ";
            cin >> n;
            editTodo(n);
        }
        else if (choice == 4)
        {
            int n;
            cout << "Enter no of todo to mark as completed : ";
                    cin >>n;
            markAsCompleted(n);
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}