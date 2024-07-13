#include<iostream>
using namespace std;

struct employeeRecord{
    int id;
    string first_name,middle_name,last_name;
    string address;
};

// 

void searchById(struct employeeRecord e[],int id,int size){
int count=0;

// cout<<endl<<"Employees with id "<<id<<" and address: "<<add<<endl;
cout<<"\nResult:"<<endl;
for(int i=0;i<size;i++){
    if(e[i].id==id){
        count++;
        cout<<e[i].id<<". "<<e[i].first_name<<" "<<e[i].middle_name<<" "<<e[i].last_name<<endl;
    }
}

if(count==0)
    cout<<"No Employees Found"<<endl;

}

void searchByAddress(struct employeeRecord e[],string address,int size){
int count=0;

// cout<<endl<<"Employees with id "<<id<<" and address: "<<add<<endl;
cout<<"\nResult:"<<endl;
for(int i=0;i<size;i++){
    if(e[i].address==address){
        count++;
        cout<<e[i].id<<". "<<e[i].first_name<<" "<<e[i].middle_name<<" "<<e[i].last_name<<endl;
    }
}

if(count==0)
    cout<<"No Employees Found"<<endl;

}
void searchByName(struct employeeRecord e[],string firstname,string middlename,string lastname,int size){
int count=0;

cout<<"\nResult:"<<endl;
for(int i=0;i<size;i++){
    if(e[i].first_name==firstname && e[i].middle_name==middlename && e[i].last_name==lastname){
        count++;
        cout<<e[i].id<<". "<<e[i].first_name<<" "<<e[i].middle_name<<" "<<e[i].last_name<<endl;
    }
}

if(count==0)
    cout<<"No Employees Found"<<endl;

}

int main(){

int n;
cout<<"Enter the number of employees: ";
cin>>n;

struct employeeRecord emp[n];

for(int i=0;i<n;i++){
cout<<endl<<"Enter id of employee "<<i+1<<": ";
cin>>emp[i].id;
cout<<"Enter full name of employee "<<i+1<<": ";
cin>>emp[i].first_name>>emp[i].middle_name>>emp[i].last_name;
cout<<"Enter address of employee "<<i+1<<": ";
cin>>emp[i].address;
}

int id;
string address,firstName,middleName,lastName;

cout<<"How would you like to search?"<<endl;
cout<<"1. By id"<<endl;
cout<<"2. By address"<<endl;
cout<<"3. By name"<<endl;
int choice;
cin>>choice;

switch (choice)
{
case 1:
cout<<"Enter ID to search: ";
    cin>>id;
    searchById(emp,id,n);
    break;
case 2:
cout<<"Enter Address to search: ";
    cin>>address;
    searchByAddress(emp,address,n);
    break;
case 3:
cout<<"Enter Full Name: ";
    cin>>firstName>>middleName>>lastName;
    searchByName(emp,firstName,middleName,lastName,n);
    break;

default:
    break;
}

// search(emp,n,id,address);

return 0;
}
