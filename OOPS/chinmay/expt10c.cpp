#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    
    int rollNo;
    string address;
    string branch;

    void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter branch: ";
        cin >> branch;
    }

    void displayData() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Address: " << address << endl;
        cout << "Branch: " << branch << endl;
    }

    string getFileName() {
        return name + ".txt";
    }

    void saveToFile() {
        ofstream file(getFileName());
        file << name << endl;
        file << rollNo << endl;
        file << address << endl;
        file << branch << endl;
        file.close();
    }

    void loadFromFile(string fileName) {
        ifstream file(fileName);
        if (file.is_open()) {
            getline(file, name);
            file >> rollNo;
            file.ignore();
            getline(file, address);
            getline(file, branch);
            file.close();
        } else {
            cout << "File not found!" << endl;
        }
    }
};

void searchAndUpdateStudent(int rollNo) {
    ifstream file;
    string fileName;
    Student student;
    bool found = false;

    cout << "Enter the name of the student to search: ";
    cin >> fileName;
    fileName += ".txt";

    student.loadFromFile(fileName);

    if (student.rollNo == rollNo) {
        found = true;
        cout << "Student found!" << endl;
        student.displayData();
        cout << "Do you want to update the details? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            student.getData();
            student.saveToFile();
            cout << "Details updated successfully!" << endl;
        }
    }

    if (!found) {
        cout << "Student with roll number " << rollNo << " not found!" << endl;
    }
}

int main() {
    int choice;
    Student student;

    while (true) {
        cout << "1. Add Student" << endl;
        cout << "2. Search and Update Student" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                student.getData();
                student.saveToFile();
                break;
            case 2:
                int rollNo;
                cout << "Enter roll number to search: ";
                cin >> rollNo;
                searchAndUpdateStudent(rollNo);
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}