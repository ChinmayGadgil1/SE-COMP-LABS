#include<iostream>
using namespace std;

struct employeeRecord{
    int id;
    string name;
    string address;
};

void search(struct employeeRecord e[],int size,int id,string add){
int count=0;

cout<<endl<<"Employees with id "<<id<<" and address: "<<add<<endl;
for(int i=0;i<size;i++){
    if(e[i].id==id && e[i].address==add){
        count++;
        cout<<count<<". "<<e[i].name<<endl;
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
cout<<"Enter id name and address of employee "<<i+1<<":"<<endl;
cin>>emp[i].id>>emp[i].name>>emp[i].address;

}

int id;
string address;

cout<<"Enter id and address to search for employees:"<<endl;
cin>>id>>address;

search(emp,n,id,address);

return 0;
}
