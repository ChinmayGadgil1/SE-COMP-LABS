#include <iostream>
using namespace std;

class Employee
{
protected:
    int sal;
    int emp_id;

public:
    Employee()
    {
        cout << "\nEmployee Constructor Called\n";
    }
    Employee(int s, int id) : sal(s), emp_id(id)
    {
        cout << "\nEmployee Constructor Called\n";
    }
    virtual void display()
    {
        cout << "\nSalary: " << sal;
        cout << "\nEmployee ID: " << emp_id << endl;
    }
    ~Employee()
    {
        cout << "\nEmployee Destructor Called\n";
    }
};

class Student
{
protected:
    string course;

public:
    Student()
    {
        cout << "\nStudent Constructor Called\n";
    }
    Student(string c) : course(c)
    {
        cout << "\nStudent Constructor Called\n";
    }
    virtual void display()
    {
        cout << "\nCourse: " << course << endl;
    }
    ~Student()
    {
        cout << "\nStudent Destructor Called\n";
    }
};

class Intern : public Employee, public Student
{
    int internship_dur;

public:
    Intern()
    {
        cout << "\nIntern Constructor Called\n";
    }
    Intern(string c, int s, int id, int dur) : Employee(s, id), Student(c), internship_dur(dur)
    {
        cout << "\nIntern Constructor Called\n";
    }
    void set()
    {
        cin.ignore();
        cout << "\nEnter details:";
        cout << "\nEnter ID: ";
        cin >> emp_id;
        cout << "Salary: ";
        cin >> sal;
        cout << "Course: ";
        cin.ignore();
        getline(cin, course);
        cout << "Internship duration (months): ";
        cin >> internship_dur;
    }
    void display()
    {
        cout << "\nId: " << emp_id;
        cout << "\nSalary: " << sal;
        cout << "\nCourse: " << course;
        cout << "\nInternship Duration(months): " << internship_dur << endl;
    }
    ~Intern()
    {
        cout << "\nIntern Destructor Called\n";
    }
};

int main()
{
    Intern n;
    Employee *ptr = NULL;

    int choice;
    do
    {
        cout << "\nMenu";
        cout << "\n1.Enter Details of intern";
        cout << "\n2.Display Details of intern";
        cout << "\n3.Exit";
        cout << "\nYour choice --> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            n.set();
            ptr = &n;
        }
        break;
        case 2:
        {
            if (ptr == NULL)
            {
                cout << "\nEnter details of intern first\n";
            }
            else
            {
                ptr->display();
            }
        }
        default:
            break;
        }

    } while (choice != 3);

    delete ptr;
    return 0;
}