#include <iostream>
#include <queue>

using namespace std;

void displayMenu() {
    cout << "\nQueue Operations Menu:" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Front" << endl;
    cout << "4. Size" << endl;
    cout << "5. Exit" ;
}

int main() {
    queue<int> q;
    int choice, value;

        displayMenu();
    while (true) {
    cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.push(value);
                cout << value << " enqueued to the queue." << endl;
                break;
            case 2:
                if (!q.empty()) {
                    cout << q.front() << " dequeued from the queue." << endl;
                    q.pop();
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 3:
                if (!q.empty()) {
                    cout << "Front element is: " << q.front() << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 4:
                cout << "Queue size is: " << q.size() << endl;
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}