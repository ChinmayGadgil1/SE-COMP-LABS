#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
public:
    int id;
    string fullName;
    double currentSalary;

    void inputDetails()
    {
        cout << "Enter employee ID: ";
        cin >> id;
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, fullName);
        cout << "Enter current salary: ";
        cin >> currentSalary;
    }

    void increaseSalary(double increment)
    {
        if (currentSalary < 50000)
        {
            currentSalary += increment;
        }
    }

    string getPromotionStatus()
    {
        return (currentSalary >= 50000) ? "Promoted" : "Demoted";
    }
};

void printTableHeader()
{
    cout << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Salary"
         << setw(10) << "Status" << endl;
    cout << string(55, '-') << endl;
}

void printEmployeeDetails(Employee &emp)
{
    cout << setw(10) << emp.id
         << setw(20) << emp.fullName
         << setw(15) << emp.currentSalary
         << setw(10) << emp.getPromotionStatus() << endl;
}

int main()
{
    int employeeCount;
    cout << "Enter number of employees: ";
    cin >> employeeCount;
    Employee employees[employeeCount];

    for (int i = 0; i < employeeCount; ++i)
    {
        cout << "\nEnter details for employee " << i + 1 << ":\n";
        employees[i].inputDetails();
    }

    for (int i = 0; i < employeeCount; ++i)
    {
        double incrementAmount;
        cout << "Enter salary increment for " << employees[i].fullName << ": ";
        cin >> incrementAmount;
        employees[i].increaseSalary(incrementAmount);
    }

    cout << "\nEmployee Details after Salary Increment:\n";
    printTableHeader();
    for (int i = 0; i < employeeCount; ++i)
    {
        printEmployeeDetails(employees[i]);
    }

    return 0;
}
