//23B-CO-015
#include <iostream>
#include <iomanip>
using namespace std;

struct Student {
    int rollNo;
    string fullName;
    int scores[4];
    int gradePoints[4];
    double sgpa;
};

char getGrade(int marks) {
    if (marks >= 85) {
        return 'O';
    } else if (marks >= 75) {
        return 'A';
    } else if (marks >= 65) {
        return 'B';
    } else if (marks >= 55) {
        return 'C';
    } else if (marks >= 45) {
        return 'D';
    } else {
        return 'F';
    }
}

int getGradePoints(int marks) {
    if (marks >= 85 && marks <= 100) {
        return 10;
    } else if (marks >= 75) {
        return 9;
    } else if (marks >= 65) {
        return 8;
    } else if (marks >= 55) {
        return 7;
    } else if (marks >= 50) {
        return 6;
    } else if (marks >= 45) {
        return 5;
    } else if (marks >= 40) {
        return 4;
    } else {
        return 0;
    }
}

void enterStudentDetails(struct Student students[], int index) {
    cin.ignore();
    cout << "\nEnter details for Student " << index + 1 << ":" << endl;
    cout << "Name: ";
    getline(cin, students[index].fullName);

    students[index].rollNo = index + 1;

    cout << "Enter marks for subjects:" << endl;
    cout << "Mathematics: ";
    cin >> students[index].scores[0];
    cout << "Physics: ";
    cin >> students[index].scores[1];
    cout << "ICE: ";
    cin >> students[index].scores[2];
    cout << "Programming: ";
    cin >> students[index].scores[3];

    for (int i = 0; i < 4; i++) {
        students[index].gradePoints[i] = getGradePoints(students[index].scores[i]);
    }

    students[index].sgpa = (students[index].gradePoints[0] * 4 + students[index].gradePoints[1] * 3 + 
                            students[index].gradePoints[2] * 3 + students[index].gradePoints[3] * 4) / 13.0;
}

string getStatus(int marks) {
    return marks < 40 ? "Fail" : "Pass";
}

void showStudentDetails(struct Student students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "\nStudent Information:\n";
        cout << "Name: " << students[i].fullName << endl;
        cout << "Roll Number: " << students[i].rollNo << endl;
        cout << "Subject     Marks   Grade   Status" << endl;
        cout << "-----------------------------------" << endl;

        for (int j = 0; j < 4; j++) {
            switch (j) {
                case 0: cout << "Math        "; break;
                case 1: cout << "Physics     "; break;
                case 2: cout << "ICE         "; break;
                case 3: cout << "Programming "; break;
            }
            cout << students[i].scores[j] << "      " 
                 << getGrade(students[i].scores[j]) << "      " 
                 << getStatus(students[i].scores[j]) << endl;
        }
        cout << "SGPA: " << setprecision(3) << students[i].sgpa << "\n";
    }
}

int main() {
    int numberOfStudents;
    cout << "Enter number of students: ";
    cin >> numberOfStudents;
    struct Student students[numberOfStudents];
    int choice;

    while (1) {
        cout << "\nMenu:\n";
        cout << "1. Enter student details\n";
        cout << "2. Display all results\n";
        cout << "3. Quit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < numberOfStudents; i++) {
                    enterStudentDetails(students, i);
                }
                break;
            case 2:
                showStudentDetails(students, numberOfStudents);
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
