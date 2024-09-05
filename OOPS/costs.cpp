#include<iostream>
using namespace std;

class records{
    protected:
    int emp_id, ;
    char emp_name[20];
    char emp_designation[20];
    float basic, da, hra, gross, pf, net;
    public:
    void getdata(){
        cout<<"Enter the employee id: ";
        cin>>emp_id;
        cout<<"Enter the employee name: ";
        cin>>emp_name;
        cout<<"Enter the employee designation: ";
        cin>>emp_designation;
        cout<<"Enter the basic pay: ";
        cin>>basic;
        cout<<"Enter the House Rent Allowance: ";
        cin>>hra;
        cout<<"Enter the Dearness Allowance: ";
        cin>>da;
        cout<<"Enter the Provident Fund: ";
        cin>>pf;
    }
    void display(){
        cout<<"Employee ID: "<<emp_id<<endl;
        cout<<"Employee Name: "<<emp_name<<endl;
        cout<<"Employee Designation: "<<emp_designation<<endl;
        cout<<"Basic Pay: "<<basic<<endl;
        cout<<"House Rent Allowance: "<<hra<<endl;
        cout<<"Dearness Allowance: "<<da<<endl;
        cout<<"Provident Fund: "<<pf<<endl;
        cout<<"Gross Salary: "<<gross<<endl;
        cout<<"Net Salary: "<<net<<endl;
    }

};

int main(){

return 0;
}