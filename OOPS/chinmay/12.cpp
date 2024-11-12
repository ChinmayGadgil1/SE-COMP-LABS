#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

void printSet(const set<int>& mySet) {
    cout << "Elements in the set: ";
    for_each(mySet.begin(), mySet.end(), [](int x) {
        cout << x << " ";
    });
    cout << endl;
}

void findElement(const set<int>& mySet, int toFind) {
    auto it = find(mySet.begin(), mySet.end(), toFind);
    if (it != mySet.end()) {
        cout << "Element " << toFind << " found in the set." << endl;
    } else {
        cout << "Element " << toFind << " not found in the set." << endl;
    }
}

void countElement(const set<int>& mySet, int toCount) {
    int count = std::count(mySet.begin(), mySet.end(), toCount);
    cout << "Element " << toCount << " occurs " << count << " times in the set." << endl;
}

void copySet(const set<int>& mySet, set<int>& anotherSet) {
    copy(mySet.begin(), mySet.end(), inserter(anotherSet, anotherSet.begin()));
    cout << "Elements in anotherSet: ";
    for (const int& x : anotherSet) {
        cout << x << " ";
    }
    cout << endl;
}

void findMinElement(const set<int>& mySet) {
    if (!mySet.empty()) {
        auto minElement = *min_element(mySet.begin(), mySet.end());
        cout << "Minimum element in the set is: " << minElement << endl;
    } else {
        cout << "The set is empty." << endl;
    }
}

void findMaxElement(const set<int>& mySet) {
    if (!mySet.empty()) {
        auto maxElement = *max_element(mySet.begin(), mySet.end());
        cout << "Maximum element in the set is: " << maxElement << endl;
    } else {
        cout << "The set is empty." << endl;
    }
}



int main() {
    set<int> mySet;
    int n, element;
    cout << "Enter the number of elements you want to insert: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        mySet.insert(element);
    }
    set<int> anotherSet;
    int choice;

    cout << "\nMenu:\n";
    cout << "1. Print all elements\n";
    cout << "2. Find an element\n";
    cout << "3. Count occurrences of an element\n";
    cout << "4. Copy elements to another set\n";
    cout << "5. Find minimum element\n";
    cout << "6. Find maximum element\n";
    cout << "7. Exit";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printSet(mySet);
                break;
            case 2:
                cout << "Enter element to find: ";
                cin >> element;
                findElement(mySet, element);
                break;
            case 3:
                cout << "Enter element to count: ";
                cin >> element;
                countElement(mySet, element);
                break;
            case 4:
                copySet(mySet, anotherSet);
                break;
            case 5:
                findMinElement(mySet);
                break;
            case 6:
                findMaxElement(mySet);
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
