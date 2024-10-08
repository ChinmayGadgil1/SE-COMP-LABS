#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Item {
    string name;
    int code;
    double cost;
};

void printLine() {
    cout << setfill('-') << setw(72) << "-" << setfill(' ') << "\n";
}

void printHeader() {
    printLine();
    cout << "|" << setw(18) << "NAME" << setw(18) << "CODE" << setw(18) << "COST" << setw(17) << "|\n";
    printLine();
}

void printItem(const Item& item) {
    cout << "|" << setw(21) << item.name << setw(15) << item.code << setw(19) << fixed << setprecision(2) << item.cost << setw(16) << "|\n";
}

void printMenu() {
    cout << "Menu:\n";
    cout << "1. Add Item\n";
    cout << "2. Display Items\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<Item> items;
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                Item newItem;
                cout << "Enter item name: ";
                cin.ignore();
                getline(cin, newItem.name);
                cout << "Enter item code: ";
                cin >> newItem.code;
                cout << "Enter item cost: ";
                cin >> newItem.cost;
                items.push_back(newItem);
                break;
            }
            case 2: {
                printHeader();
                for (const auto& item : items) {
                    printItem(item);
                }
                printLine();
                break;
            }
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}