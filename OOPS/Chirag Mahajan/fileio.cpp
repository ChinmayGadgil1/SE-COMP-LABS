#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Student {
    string id;
    string name;
    string grade;
};

void displayRecords() {
    ifstream file("students.csv");
    string line;
    cout << "ID, Name, Grade\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void addRecord() {
    ofstream file("students.csv", ios::app);
    Student student;
    cout << "Enter ID: ";
    cin >> student.id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter Grade: ";
    cin >> student.grade;

    file << student.id << "," << student.name << "," << student.grade << endl;
    file.close();
    cout << "Record added successfully.\n";
}

void editRecord() {
    ifstream file("students.csv");
    ofstream tempFile("temp.csv");
    Student student;
    string line, id;
    bool found = false;

    cout << "Enter ID of the student to edit: ";
    cin >> id;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, student.id, ',');
        getline(ss, student.name, ',');
        getline(ss, student.grade, ',');

        if (student.id == id) {
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, student.name);
            cout << "Enter new Grade: ";
            cin >> student.grade;
            found = true;
        }

        tempFile << student.id << "," << student.name << "," << student.grade << endl;
    }

    file.close();
    tempFile.close();

    remove("students.csv");
    rename("temp.csv", "students.csv");

    if (found) {
        cout << "Record updated successfully.\n";
    } else {
        cout << "Record with ID " << id << " not found.\n";
    }
}

void deleteRecord() {
    ifstream file("students.csv");
    ofstream tempFile("temp.csv");
    Student student;
    string line, id;
    bool found = false;

    cout << "Enter ID of the student to delete: ";
    cin >> id;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, student.id, ',');
        getline(ss, student.name, ',');
        getline(ss, student.grade, ',');

        if (student.id != id) {
            tempFile << student.id << "," << student.name << "," << student.grade << endl;
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    remove("students.csv");
    rename("temp.csv", "students.csv");

    if (found) {
        cout << "Record deleted successfully.\n";
    } else {
        cout << "Record with ID " << id << " not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nStudent Records Management System\n";
        cout << "1. Display Records\n";
        cout << "2. Add Record\n";
        cout << "3. Edit Record\n";
        cout << "4. Delete Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: displayRecords(); break;
            case 2: addRecord(); break;
            case 3: editRecord(); break;
            case 4: deleteRecord(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
