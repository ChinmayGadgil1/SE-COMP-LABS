#include <iostream>
#include <vector>
using namespace std;

int main() {
vector<int> numbers;
int choice, n, input;

do {
    cout << "\nMenu:\n";
    cout << "1. Add elements to vector\n";
    cout << "2. Display vector elements\n";
    cout << "3. Modify element\n";
    cout << "4. Pop back element\n";
    cout << "5. Display vector size\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter the number of elements: ";
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cout << "Enter element " << i + 1 << ": ";
                cin >> input;
                numbers.push_back(input);
            }
            break;

        case 2:
            cout << "Vector elements: ";
            for (int num : numbers) {
                cout << num << " ";
            }
            cout << endl;
            break;

        case 3:
            if (!numbers.empty()) {
                int index, newValue;
                cout << "Enter the index of the element to modify: ";
                cin >> index;
                if (index >= 0 && index < numbers.size()) {
                    cout << "Enter the new value: ";
                    cin >> newValue;
                    numbers[index] = newValue;
                    cout << "Modified element at index " << index << ": " << numbers[index] << endl;
                } else {
                    cout << "Invalid index." << endl;
                }
            } else {
                cout << "Vector is empty, cannot modify elements." << endl;
            }
            break;

        case 4:
            if (!numbers.empty()) {
                numbers.pop_back();
                cout << "Vector after pop_back: ";
                for (int num : numbers) {
                    cout << num << " ";
                }
                cout << endl;
            } else {
                cout << "Vector is empty, cannot pop back." << endl;
            }
            break;

        case 5:
            cout << "Vector size: " << numbers.size() << endl;
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
    }
} while (choice != 6);

    return 0;
}