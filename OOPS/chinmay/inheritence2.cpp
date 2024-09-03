# include<iostream>
#include<string>
using namespace std;

class Staff{
    protected:
    int code;
    string name;
    public:
        Staff(int c,string n):code(c),name(n){}
};

class Officer:public Staff{
    char grade;
    public:
    Officer(int c, string n,char g):Staff(c,n){
        grade=g;
    }
    void display(){
        cout<<"\ncode: "<<code<<endl;
        cout<<"name: "<<name<<endl;
        cout<<"grade: "<<grade<<endl;
    }
};

class Typist:public Staff{
    protected:
    int speed;
    public:
    Typist(int c, string n,int s):Staff(c,n){
        speed=s;
    }
};

class casual: public Typist{
    int daily_wages;
    public:
        casual(int c,string n,int s,int w):Typist(c, n,s){
            daily_wages=w;
        }
        void display(){
        cout<<"\ncode: "<<code<<endl;
        cout<<"name: "<<name<<endl;
        cout<<"daily wages: "<<daily_wages<<endl;
        cout<<"Typing speed: "<<speed<<endl;
    }
};
class regular: public Typist{ 
    int salary;
    public:
    regular(int c,string n,int s,int sal):Typist(c, n,s){
        salary=sal;
    }
    void display(){
        cout<<"\ncode: "<<code<<endl;
        cout<<"name: "<<name<<endl;
        cout<<"salary: "<<salary<<endl;
        cout<<"Typing speed: "<<speed<<endl;
    }
};
class Teacher:public Staff{
    string sub;
    string publication;
    public:
    Teacher(int c, string n,string s,string pub):Staff(c,n){
     sub=s;
     publication=pub;   
    }
    void display(){
        cout<<"\ncode: "<<code<<endl;
        cout<<"name: "<<name<<endl;
        cout<<"subject: "<<sub<<endl;
        cout<<"publication: "<<publication<<endl;
    }
};

int main(){
int choice;
label:
cout<<"Enter type of staff\n";
cout<<"1.Teacher"<<endl;
cout<<"2.Casual Typist"<<endl;
cout<<"3.Regular Typist"<<endl;
cout<<"4.Officer"<<endl;
cin>>choice;
if(choice<1 && choice>4){
    cout<<"Invalid choice enter again\n";
    goto label;
}

if(choice==1){
    int code;
    string name;
    string sub;
    string pub;
    cin.ignore();

    cout<<"Enter name: ";
    getline(cin,name);
    cout<<"Enter code: ";
    cin>>code;
    cin.ignore();

    cout<<"Enter subject: ";
    getline(cin,sub);

    cout<<"Enter publication: ";
    getline(cin,pub);
    Teacher t(code,name,sub,pub);
    t.display();
}
else if (choice==2)
{
    int code;
    string name;
    
    int s,w;
    cin.ignore();

    cout<<"Enter name: ";
    getline(cin,name);
    // cin.ignore();

    cout<<"Enter code: ";
    cin>>code;
    cout<<"Enter typing speed: ";
    cin>>s;
    cout<<"Enter daily wages: ";
    cin>>w;
    casual c(code,name,s,w);
    c.display();
}
else if (choice==3)
{
    int code;
    string name;
    int s,w;
    cin.ignore();
    cout<<"Enter name: ";
    getline(cin,name);
    cout<<"Enter code: ";
    cin>>code;
    cout<<"Enter typing speed: ";
    cin>>s;
    cout<<"Enter salary: ";
    cin>>w;
    regular c(code,name,s,w);
    c.display();
}
else
{
    int code;
    string name;
    char g;
    int s,w;
    cin.ignore();

    cout<<"Enter name: ";
    getline(cin,name);
    cout<<"Enter code: ";
    cin>>code;
    cout<<"Enter grade: ";
    cin>>g;
    Officer o(code,name,g);
    o.display();
}



return 0;
}   