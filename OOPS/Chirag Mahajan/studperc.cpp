#include<iostream>
using namespace std;

class Student{
    string student_name;
    int roll_no;
    float percentage;
    int subject_marks[4];
public:
    void CalculatePercentage(){
        percentage = (subject_marks[0] + subject_marks[1] + subject_marks[2] + subject_marks[3]) / 4.0;
    }
    void InputDetails(){
        cin.ignore();
        cout << "Enter Student's Name: ";
        getline(cin, student_name);
        cout << "Roll Number: ";
        cin >> roll_no;
        cout << "Enter marks for 4 subjects:" << endl;
        for(int i=0; i<4; i++){
            cout << "Subject " << i+1 << ": ";
            cin >> subject_marks[i];
        }
        CalculatePercentage();
    }
    void ShowDetails(){
        cout << "Student's Name: " << student_name << endl;
        cout << "Roll Number: " << roll_no << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main(){
    int num_students;
    cout << "How many students' details do you want to enter? ";
    cin >> num_students;

    Student *students = new Student[num_students];

    cout << "\nPlease enter the details below:" << endl;
    for(int i=0; i<num_students; i++){
        cout << "\nStudent " << i+1 << " Details:" << endl;
        students[i].InputDetails();
    }

    for(int i=0; i<num_students; i++){
        cout << "\nDetails of Student " << i+1 << ":" << endl;
        students[i].ShowDetails();
    }

    delete[] students;
    return 0;
}
