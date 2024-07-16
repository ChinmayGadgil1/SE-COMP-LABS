#include <iostream>
#include <iomanip>
using namespace std;

struct Student {
    int rollNumber;
    string name;
    int marks[4];
    int gp[4];
    double sgpa;
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
int calculateGradePoints(int marks) {
    if (marks >= 85 && marks<=100) {
        return 10;
    } else if (marks >= 75) {
        return 9;
    } else if (marks >= 65) {
        return 8;
    } else if (marks >= 55) {
        return 7;
    } else if (marks >= 50) {
        return 6;
    } 
    else if (marks>=45)
    {
        return 5;
    }
    else if (marks>=40)
    {
        return 4;
    }
    else {
        return 0;
    }
}

void inputStudentData(struct Student students[], int index) {
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
    students[index].gp[0]=calculateGradePoints(students[index].marks[0]);
    students[index].gp[1]=calculateGradePoints(students[index].marks[1]);
    students[index].gp[2]=calculateGradePoints(students[index].marks[2]);
    students[index].gp[3]=calculateGradePoints(students[index].marks[3]);

    students[index].sgpa=(double)(students[index].gp[0]*4+students[index].gp[1]*3+students[index].gp[2]*3+students[index].gp[3]*4)/13.0;
}

string passes(int marks) {
    return marks < 40 ? "Fail" : "Pass";
}

void displayStudentData(struct Student students[], int size) {
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
        cout<<"SGPA: "<<setprecision(3)<<students[i].sgpa<<"\n";
    }
}

int main() {
    int size;
    cout << "Enter number of students: ";
    cin >> size;
    struct Student students[size];
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
