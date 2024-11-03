#include <iostream>
#include <deque>

using namespace std;

void displayDeque(const deque<int>& dq) {
    for (int num : dq) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    deque<int> dq;
    int choice, value;

        cout << "\nMenu:\n";
        cout << "1. Insert at front\n";
        cout << "2. Insert at back\n";
        cout << "3. Delete from front\n";
        cout << "4. Delete from back\n";
        cout << "5. Display deque\n";
        cout << "6. Exit";
    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                dq.push_front(value);
                break;
            case 2:
                cout << "Enter value to insert at back: ";
                cin >> value;
                dq.push_back(value);
                break;
            case 3:
                if (!dq.empty()) {
                    dq.pop_front();
                    cout << "Deleted from front.\n";
                } else {
                    cout << "Deque is empty.\n";
                }
                break;
            case 4:
                if (!dq.empty()) {
                    dq.pop_back();
                    cout << "Deleted from back.\n";
                } else {
                    cout << "Deque is empty.\n";
                }
                break;
            case 5:
                cout << "Deque contents: ";
                displayDeque(dq);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}