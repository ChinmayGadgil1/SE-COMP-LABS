#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int rollNumber;
    string name;
    int marks[4];
};

char calculateGrade(int marks) {
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

void inputStudentData(Student students[], int index) {
    cin.ignore();
    cout << "\nEnter student's details for Student " << index + 1 << ":" << endl; 
    cout << "Enter student's name: ";
    getline(cin, students[index].name);

    students[index].rollNumber=index+1;

    cout << "Enter subjects and marks for semester:" << endl;
    cout << "Enter math marks: ";
    cin >> students[index].marks[0];
    cout << "Enter physics marks: ";
    cin >> students[index].marks[1];
    cout << "Enter ICE marks: ";
    cin >> students[index].marks[2];
    cout << "Enter Prog. marks: ";
    cin >> students[index].marks[3];
}

string passes(int marks) {
    return marks < 40 ? "Fail" : "Pass";
}

void displayStudentData(Student students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "\nStudent Information:\n";
        cout << "Name: " << students[i].name << endl;
        cout << "Roll No: " << students[i].rollNumber << endl;
        cout << "Subject  Marks  Grade Status" << endl;
        cout << "----------------------------" << endl;

        for (int j = 0; j < 4; j++) {
            
            switch (j)
            {
            case 0:cout<<"Math     ";
                break;
            case 1:cout<<"Phy.     ";
                break;
            case 2:cout<<"ICE      ";
                break;
            case 3:cout<<"Prog     ";
                break;
            
            }
            cout << students[i].marks[j] << "     " 
                 << calculateGrade(students[i].marks[j]) << "     " 
                 << passes(students[i].marks[j]) << endl;
        }
    }
}

int main() {
    int size;
    cout << "Enter number of students: ";
    cin >> size;
    Student students[size];
    int choice;

    while (1) {
        cout << "\nMenu:\n";
        cout << "1. Add student data\n";
        cout << "2. Display all results\n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                    for (int i = 0; i < size; i++)
                    {   
                    inputStudentData(students, i);
                    }
                break;
            case 2:
                displayStudentData(students, size);
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
