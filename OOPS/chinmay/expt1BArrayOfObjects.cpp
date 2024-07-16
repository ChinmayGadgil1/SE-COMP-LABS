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
    cout<<"Name                         "<<"Author                          "<<"Price               "<<"No. Of Pages\n";
    cout<<"--------------------------------------------------------------------\n";
    for (int i = 0; i < s; i++)
    {
        cout<<b[i].name<<"      "<<b[i].author<<"               "<<b[i].price<<"                "<<b[i].no_of_pages<<"\n";
    }
}

int main(){
int size;
cin>>size;

book * b=new book[size];

inputInfo(b,size);
displayInfo(b,size);


delete[] b;
return 0;
}