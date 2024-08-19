#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    float cgpa;

public:

    Student(string n, int a, float g) {
        name = n;
        age = a;
        cgpa = g;
    }


    Student(const Student &stu) {
        name = stu.name;
        age = stu.age;
        cgpa = stu.cgpa;
    }


    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "GPA: " << cgpa << endl;
    }
};

int main() {
    string name;
    int age;
    float gpa;


    cout << "Enter student's name: ";
    getline(cin, name);
    cout << "Enter student's age: ";
    cin >> age;
    cout << "Enter student's CGPA: ";
    cin >> gpa;

    
    Student student1(name, age, gpa);

    
    Student student2 = student1;

  
    cout << "\nDetails of Student 1:" << endl;
    student1.display();

    cout << "\nDetails of Student 2 (Copied from Student 1):" << endl;
    student2.display();

    return 0;
}
