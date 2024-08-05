#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
private:
    int rollNumber;
    string name;
    int marks[4];
    int gp[4];
    double sgpa;

public:
    void inputStudentData(int);
    char calculateGrade(int);
    int calculateGradePoints(int);
    string passes(int);
    void displayStudentData();
};

char Student::calculateGrade(int marks)
{
    if (marks >= 85)
    {
        return 'O';
    }
    else if (marks >= 75)
    {
        return 'A';
    }
    else if (marks >= 65)
    {
        return 'B';
    }
    else if (marks >= 55)
    {
        return 'C';
    }
    else if (marks >= 45)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

int Student::calculateGradePoints(int marks)
{
    if (marks >= 85 && marks <= 100)
    {
        return 10;
    }
    else if (marks >= 75)
    {
        return 9;
    }
    else if (marks >= 65)
    {
        return 8;
    }
    else if (marks >= 55)
    {
        return 7;
    }
    else if (marks >= 50)
    {
        return 6;
    }
    else if (marks >= 45)
    {
        return 5;
    }
    else if (marks >= 40)
    {
        return 4;
    }
    else
    {
        return 0;
    }
}

void Student::inputStudentData(int index)
{
    cin.ignore();
    cout << "\nEnter student's details for Student " << index + 1 << ":" << endl;
    cout << "Enter student's name: ";
    getline(cin, name);

    rollNumber = index + 1;

    cout << "Enter subjects and marks for semester:" << endl;
    cout << "Enter math marks: ";
    cin >> marks[0];
    cout << "Enter physics marks: ";
    cin >> marks[1];
    cout << "Enter ICE marks: ";
    cin >> marks[2];
    cout << "Enter Prog. marks: ";
    cin >> marks[3];
    gp[0] = calculateGradePoints(marks[0]);
    gp[1] = calculateGradePoints(marks[1]);
    gp[2] = calculateGradePoints(marks[2]);
    gp[3] = calculateGradePoints(marks[3]);

    sgpa = (double)(gp[0] * 4 + gp[1] * 3 + gp[2] * 3 + gp[3] * 3) / 13.0;

    

}

string Student::passes(int marks)
{
    return marks < 40 ? "Fail" : "Pass";
}

void Student::displayStudentData()
{
    cout << "\nStudent Information:\n";
    cout << "Name: " << name << endl;
    cout << "Roll No: " << rollNumber << endl;
    cout << "Subject  Marks  Grade Status" << endl;

    for (int j = 0; j < 4; j++)
    {
        switch (j)
        {
        case 0:
            cout << "Math     ";
            break;
        case 1:
            cout << "Phy.     ";
            break;
        case 2:
            cout << "ICE      ";
            break;
        case 3:
            cout << "Prog     ";
            break;
        }
        cout << marks[j] << "     "
             << calculateGrade(marks[j]) << "     "
             << passes(marks[j]) << endl;
    }
    cout << "SGPA: " << setprecision(3) << sgpa << "\n";
}

int main()
{
    int size;
    cout << "Enter number of students: ";
    cin >> size;
    Student *students = new Student[size];
    int choice;

    while (1)
    {
        cout << "\nMenu:\n";
        cout << "1. Add student data\n";
        cout << "2. Display all results\n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            for (int i = 0; i < size; i++)
            {
                students[i].inputStudentData(i);
            }
        }
        else if (choice == 2)
        {
            for (int i = 0; i < size; i++)
            {
                students[i].displayStudentData();
            }
        }
        else if (choice == 3)
        {
            cout << "Exiting..." << endl;
            delete[] students; 
            return 0;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
