#include <iostream>
using namespace std;

class Student {
protected:
    int roll_number;
public:

    void setRollNumber(int r) {
        roll_number = r;
    }

    void showRollNumber() {
        cout << "Roll Number: " << roll_number << endl;
    }
};

class Test : public Student {
protected:
    float subject1, subject2;
public:

    void setMarks(float m1, float m2) {
        subject1 = m1;
        subject2 = m2;
    }

    void showMarks() {
        cout << "Marks in Subject 1: " << subject1 << endl;
        cout << "Marks in Subject 2: " << subject2 << endl;
    }
};


class Result : public Test {
    float total_marks;
public:
 
    void calculateTotal() {
        total_marks = subject1 + subject2;
    }


    void displayResult() {
        showRollNumber();  
        showMarks();   
        cout << "Total Marks: " << total_marks << endl; 
    }
};


int main() {
    Result student1;


    student1.setRollNumber(101);
    student1.setMarks(85.5, 90.0);

    student1.calculateTotal();
    student1.displayResult();

    return 0;
}