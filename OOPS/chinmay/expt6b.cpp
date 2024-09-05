#include<iostream>
#include<string>
using namespace std;

class Employee{
    protected:
    string name;
    int id;
    static int emCount;
    public:
    Employee():id(emCount++){}
    Employee(string n): name(n), id(emCount++){}
    virtual void display() = 0; 
    ~Employee(){}
};
int Employee::emCount=1000;

class Superviser: public Employee{
    int fixed_sal;
    public:
    Superviser(){}
    Superviser(string n,int fsal):Employee(n),fixed_sal(fsal){}
    void display(){
        cout<<"\nName: "<<name;
        cout<<"\nID: "<<id;
        cout<<"\nSalary: "<<fixed_sal<<endl;
    }
    ~Superviser(){}
};

class Cleaner:public Employee{
    int daily_wages;
    public:
    Cleaner(){}
    Cleaner(string n,int dwage):Employee(n),daily_wages(dwage){}
    void display(){
        cout<<"\nName: "<<name;
        cout<<"\nID: "<<id;
        cout<<"\nDaily Wages: "<<daily_wages<<endl;
    }
    ~Cleaner(){}
};

int main(){
    int choice;
    string name;
    int fixed_sal, daily_wages;

    Employee* emp = NULL;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create a Supervisor\n";
        cout << "2. Create a Cleaner\n";
        cout << "3. Display Employee Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter fixed salary: ";
                cin >> fixed_sal;
                emp = new Superviser(name, fixed_sal);
                break;
            case 2:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter daily wages: ";
                cin >> daily_wages;
                emp = new Cleaner(name, daily_wages);
                break;
            case 3:
                if (emp != NULL) {
                    emp->display();
                } else {
                    cout << "No employee created yet.\n";
                }
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    delete emp;

    return 0;
}