#include <iostream>
#include <list>

using namespace std;

void displayList(list<int>& lst) {
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    list<int> myList;
    int choice, value, position;
    list<int>::iterator it;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add element to the front\n";
        cout << "2. Add element to the back\n";
        cout << "3. Remove element from the front\n";
        cout << "4. Remove element from the back\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add to the front: ";
                cin >> value;
                myList.push_front(value);
                break;
            case 2:
                cout << "Enter value to add to the back: ";
                cin >> value;
                myList.push_back(value);
                break;
            case 3:
                if (!myList.empty()) {
                    myList.pop_front();
                    cout << "Element removed from the front.\n";
                } else {
                    cout << "List is empty.\n";
                }
                break;
            case 4:
                if (!myList.empty()) {
                    myList.pop_back();
                    cout << "Element removed from the back.\n";
                } else {
                    cout << "List is empty.\n";
                }
                break;
            case 5:
                cout << "List elements: ";
                displayList(myList);
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