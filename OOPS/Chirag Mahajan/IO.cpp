#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Result{
    public:
    friend void display(Employee a, Result r){
    }
};

class Employee{
    protected:
        int empId;
        string empName;
        string designation;
    public:
        void setEmp(int id, string name, string desg)
        {
            empId = id;
            empName = name;
            designation = desg;
        }

        void dispEmp(){
            cout<<setw(8)<<empId<<setw(12)<<empName<<setw(12)<<designation;
        }
};

class Salary:public Employee{
    protected: 
        float basicPay, hra, da, pf;
        public:
            void setSalary(float bp, float h, float d, float p){
                basicPay=bp;
                hra=h;
                da=d;
                pf=p;
            }

            void dispSalary(){
                cout<<setw(10)<<basicPay<<setw(8)<<hra<<setw(8)<<da<<setw(8)<<pf;
            }

};

class Result:public Salary{

};