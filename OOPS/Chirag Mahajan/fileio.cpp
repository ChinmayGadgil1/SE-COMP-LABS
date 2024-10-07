#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Structure to hold student data
struct Student {
    string id;
    string name;
    string grade;
};

// Function to read student records from a CSV file
vector<Student> readRecords(const string& filename) {
    vector<Student> students;
    ifstream file(filename);
    string line, word;

    while (getline(file, line)) {
        stringstream s(line);
        Student student;
        getline(s, student.id, ',');
        getline(s, student.name, ',');
        getline(s, student.grade, ',');
        students.push_back(student);
    }
    file.close();
    return students;
}

// Function to write student records to a CSV file
void writeRecords(const string& filename, const vector<Student>& students) {
    ofstream file(filename);
    for (const auto& student : students) {
        file << student.id << "," << student.name << "," << student.grade << "\n";
    }
    file.close();
}

// Function to add a new student record
void addRecord(vector<Student>& students) {
    Student student;
    cout << "Enter student ID: ";
    cin >> student.id;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter student grade: ";
    cin >> student.grade;
    students.push_back(student);
}

// Function to edit an existing student record
void editRecord(vector<Student>& students) {
    string id;
    cout << "Enter student ID to edit: ";
    cin >> id;
    for (auto& student : students) {
        if (student.id == id) {
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, student.name);
            cout << "Enter new grade: ";
            cin >> student.grade;
            return;
        }
    }
    cout << "Student ID not found.\n";
}

// Function to delete a student record
void deleteRecord(vector<Student>& students) {
    string id;
    cout << "Enter student ID to delete: ";
    cin >> id;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "Record deleted.\n";
            return;
        }
    }
    cout << "Student ID not found.\n";
}

// Main function
int main() {
    string filename = "students.csv";
    vector<Student> students = readRecords(filename);
    int choice;

    do {
        cout << "\nStudent Records Management\n";
        cout << "1. Add Record\n";
        cout << "2. Edit Record\n";
        cout << "3. Delete Record\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord(students);
                break;
            case 2:
                editRecord(students);
                break;
            case 3:
                deleteRecord(students);
                break;
            case 4:
                writeRecords(filename, students);
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}