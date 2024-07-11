# include<iostream>
using namespace std;

class student{
    public:
    string first_name;
    string last_name;
    int marks[4];
    int GP;
    float percentage;
    bool passed;
};

int calcGP(int n){
    int gp;
    if (n >= 85)
    {
        gp = 10;
    }
    else if (n >= 75)
    {
        gp = 9;
    }

    else if (n >= 65)
    {
        gp = 8;
    }

    else if (n >= 55)
    {
        gp = 7;
    }

    else if (n >= 50)
    {
        gp = 6;
    }

    else if (n >= 45)
    {
        gp = 5;
    }

    else if (n >= 40)
    {
        gp = 4;
    }
    else
    {
        gp = 0;
    }
    return gp;
}


int main(){
int n;
cout<<"Enter number of students: ";
cin>>n;

student s[n];

for (int i = 0; i < n; i++)
{
    cout<<"\nEnter details of student "<<i+1<<" :"<<endl;
    cout<<"Enter name: ";
    cin>>s[i].first_name>>s[i].last_name;
    cout<<"Enter marks:"<<endl;
    cout<<"Math: ";
    cin>>s[i].marks[0];
    cout<<"Physics: ";
    cin>>s[i].marks[1];
    cout<<"ICE: ";
    cin>>s[i].marks[2];
    cout<<"Programming: ";
    cin>>s[i].marks[3];
    s[i].percentage=(float)(s[i].marks[0]+s[i].marks[1]+s[i].marks[2]+s[i].marks[3])/4.0;
    s[i].GP=calcGP(s[i].percentage);
    if (s[i].GP==0)
    {
        s[i].passed=false;
    }
    else
    {
        s[i].passed=true;
    }
    
    
}

for (int i = 0; i < n; i++)
{
    cout<<"\nStudent "<<i+1<<endl;
    cout<<"Name: "<<s[i].first_name<<" "<<s[i].last_name<<endl;
    cout<<"Percentage: "<<s[i].percentage<<endl;
    cout<<"Grade: "<<s[i].GP<<endl;
    if (s[i].passed)
    {
        cout<<"Status: Student has passed"<<endl;
    }
    else
    {
        cout<<"Status: Student has Failed"<<endl;
    }
    
}


return 0;
}