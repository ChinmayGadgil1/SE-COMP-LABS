#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
    }
    
    void showDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};


class Employee : virtual public Person {
protected:
    string company;
public:
    Employee() {
        cout << "Enter company name: ";
        getline(cin, company);
    }

    void showDetails() {
        Person::showDetails();
        cout << "Company: " << company << endl;
    }
};


class Student : virtual public Person {
protected:
    string college;
public:
    Student() {
        cout << "Enter college name: ";
        getline(cin, college);
    }

    void showDetails() {
        Person::showDetails();
        cout << "College: " << college << endl;
    }
};


class WorkingStudent : public Employee, public Student {
private:
    string jobTitle;
public:
    WorkingStudent() {
        cout << "Enter job title: ";
        getline(cin, jobTitle);
    }

    void display() {
        cout << "=== Working Student Details ===" << endl;
        Person::showDetails();
        cout << "Company: " << company << endl;
        cout << "College: " << college << endl;
        cout << "Job Title: " << jobTitle << endl;
    }
};

int main() {
    WorkingStudent ws;
    ws.display();
    return 0;
}
