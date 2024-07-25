#include <iostream>
#include <iomanip>
using namespace std;

class employee
{
    double salary;
    string name;
    bool isPromoted;
    string code;

public:
    void input();
    void getdata();
    void changeSal(double);
    string getcode();
};
void employee::input()
{
    cout << "\nEnter employee code: ";
    cin >> code;
    cin.ignore();
    cout << "Enter employee name: ";
    getline(cin, name);
    cout << "Enter employee salary: ";
    cin >> salary;
    salary >= 50000 ? isPromoted = true : isPromoted = false;
}

void employee::getdata()
{
    cout << code << "       ";
    cout << name << " \t\t\t";
    cout << setprecision(7) << salary << "       \t";
    if (isPromoted)
    {
        cout << "Promoted\n";
    }
    else
    {
        cout << "Demoted\n";
    }
}

string employee::getcode(){
    return code;
}


void employee::changeSal(double n)
{
    salary += n;
    salary >= 50000 ? isPromoted = true : isPromoted = false;
}

int main()
{

    int n;
    cout << "Enter number of Employees: ";
    cin >> n;
    employee emp[n];

    double salary;
    string name, code;
    int choice;
    double hike;

    while (1)
    {
        cout << "\nWhat would you like to do?\n";
        cout << "1.Add Employee Info\n";
        cout << "2.Increment/Decrement Employee Salary\n";
        cout << "3.Display Employee Info\n";
        cout << "4.Quit\n";
        cout << "Your choice=> ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                emp[i].input();
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                cout << "\nEnter amount to add to salary for employee " << i + 1 << ": ";
                cin >> hike;
                emp[i].changeSal(hike);
            }

        case 3:
            cout << "Code\t\t\t" << "Name\t\t\t\t" << "Salary\t\t" << "Status\t\t\t\n";
            for (int i = 0; i < n; i++)
            {
                emp[i].getdata();
            }
            break;
        case 4:
            exit(1);
        }
    }

    return 0;
}