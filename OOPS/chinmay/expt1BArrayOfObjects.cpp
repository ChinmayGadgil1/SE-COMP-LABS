# include<iostream>
using namespace std;

class book{
    public:
    string author;
    string name;
    double price;
    int no_of_pages;
};

void inputInfo(book* b,int s){
    for (int i = 0; i < s; i++)
    {
        cout<<"Enter info of book "<<i+1<<"\n";
        cout<<"Enter name:\n";
        cin.ignore();
        getline(cin, b[i].name);
        cout<<"Enter author name:\n";
        cin.ignore();
        getline(cin, b[i].author);
        cout<<"Enter price:\n";
        cin>>b[i].price;
        cout<<"Enter no. of pages:\n";
        cin>>b[i].no_of_pages;
    }
    
}

void displayInfo(book* b,int s){
    for (int i = 0; i < s; i++)
    {
        cout<<"Info of book "<<i+1<<"\n";
        cout<<"name:\n";
        cin.ignore();
        getline(cin, b[i].name);
        cout<<"author name:\n";
        cin.ignore();
        getline(cin, b[i].author);
        cout<<"Enter price:\n";
        cin>>b[i].price;
        cout<<"Enter no. of pages:\n";
        cin>>b[i].no_of_pages;
    }
}

int main(){

book * b=new book[4];




delete[] b;
return 0;
}