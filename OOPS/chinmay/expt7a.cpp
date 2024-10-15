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
    cout.fill('-');
    cout.width(72);
    cout << "\n";
    cout.fill(' ');
}

void printHeader() {
    printLine();
    cout << "|";
    cout.width(18);
    cout << "NAME";
    cout.width(18);
    cout << "CODE";
    cout.width(18);
    cout << "COST";
    cout.width(17);
    cout << "|\n";
    printLine();
}

void printItem(const Item& item) {
    cout << "|";
    cout.width(21);
    cout << item.name;
    cout.width(15);
    cout << item.code;
    cout.width(19);
    cout << fixed << setprecision(2) << item.cost;
    cout.width(16);
    cout << "|\n";
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