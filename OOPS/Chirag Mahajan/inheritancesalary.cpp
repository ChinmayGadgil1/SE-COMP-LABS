#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee {
protected:
    int empId;
    string empName;
    string designation;
public:
    void setEmp(int id, string name, string desg) {
        empId = id;
        empName = name;
        designation = desg;
    }
    void dispEmp() {
        cout << setw(8) << empId 
             << setw(12) << empName 
             << setw(12) << designation;
    }
};

class Salary : public Employee {
protected:
    float basicPay, hra, da, pf;
public:
    void setSalary(float bp, float h, float d, float p) {
        basicPay = bp;
        hra = h;
        da = d;
        pf = p;
    }
    void setSalary() {
        cout << setw(10) << basicPay << setw(8) << hra << setw(8) << da << setw(8) << pf;
    }
};

class Result : public Salary {
    float netPay;
public:
    void calculateNetPay() {
        netPay = basicPay + hra + da - pf;
    }
    float getNetPay() {
        return netPay;
    }
    void displayResult() {
        dispEmp();
        setSalary();
        cout << setw(8) << netPay << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of records: ";
    cin >> n;
    
    Result employees[10];
    int empId;
    string empName, designation;
    float basicPay, hra, da, pf;

    for (int i = 0; i < n; i++) {
        cout << "Enter the Employee Id: ";
        cin >> empId;
        cout << "Enter the employee name: ";
        cin >> empName;
        cout << "Enter the designation: ";
        cin >> designation;
        cout << "Enter the basic pay: ";
        cin >> basicPay;
        cout << "Enter the House Rent Allowance: ";
        cin >> hra;
        cout << "Enter the Dearness Allowance: ";
        cin >> da;
        cout << "Enter the Provident Fund: ";
        cin >> pf;

        employees[i].setEmp(empId, empName, designation);
        employees[i].setSalary(basicPay, hra, da, pf);
        employees[i].calculateNetPay();
    }

    cout << "\n"
         << setw(8) << "EmpId" 
         << setw(12) << "EmpName" 
         << setw(12) << "Designation"
         << setw(10) << "BasicPay"
         << setw(8) << "HRA"
         << setw(8) << "DA"
         << setw(8) << "PF"
         << setw(8) << "NetPay" << endl;
         
    for (int i = 0; i < n; i++) {
        employees[i].displayResult();
    }

    int highestPay = 0;
    for (int i = 1; i < n; i++) {
        if (employees[i].getNetPay() > employees[highestPay].getNetPay()) {
            highestPay = i;
        }
    }

    
    cout << "\nEmployee with the highest Net Pay:\n";
    employees[highestPay].displayResult();

    return 0;
}
