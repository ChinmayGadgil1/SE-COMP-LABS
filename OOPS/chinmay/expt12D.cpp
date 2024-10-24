#include <iostream>
#include <stack>

using namespace std;

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Top" << endl;
    cout << "4. Check if Empty" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    stack<int> s;
    int choice, value;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                cout << value << " pushed onto the stack." << endl;
                break;
            case 2:
                if (!s.empty()) {
                    cout << s.top() << " popped from the stack." << endl;
                    s.pop();
                } else {
                    cout << "Stack is empty. Cannot pop." << endl;
                }
                break;
            case 3:
                if (!s.empty()) {
                    cout << "Top element is: " << s.top() << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            case 4:
                if (s.empty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}