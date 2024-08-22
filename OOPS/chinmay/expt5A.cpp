#include <iostream>
using namespace std;

class Student
{
protected:
    int reg_no;

public:
    void get_reg_no()
    {
        cout << "Enter the registration number: ";
        cin >> reg_no;
    }
    void put_reg_no()
    {
        cout << "Registration number: " << reg_no << endl;
    }
};

class Arts : public Student
{
    int fine_arts;

public:
    void get_marks()
    {
        cout << "Enter the marks in fine arts: ";
        cin >> fine_arts;
    }
    void put_marks()
    {
        cout <<"marks in fine arts: "<< fine_arts<<endl;
    }
};

class Engineering : public Student
{
protected:
    int math_marks;

public:
    void get_marks()
    {
        cout << "Enter the marks in mathematics: ";
        cin >> math_marks;
    }
    void put_marks()
    {
        cout <<"marks in mathematics: "<<math_marks<<endl;
    }
};

class Mech : public Engineering
{
    int automobile_marks;

public:
    void get_marks()
    {
        cout << "Enter the marks in automobile: ";
        cin >> automobile_marks;
    }
    void put_marks()
    {
        cout << "Marks in automobile: " << automobile_marks << endl;
    }
};

class ETC : public Engineering
{
    int electronics_marks;

public:
    void get_marks()
    {
        cout << "Enter the marks in electronics: ";
        cin >> electronics_marks;
    }
    void put_marks()
    {
        cout << "Marks in electronics: " << electronics_marks << endl;
    }
};

class Comp : public Engineering
{
    int OOPS_marks;

public:
    void get_marks()
    {
        cout << "Enter the marks in Object Oriented Programming System: ";
        cin >> OOPS_marks;
    }
    void put_marks()
    {
        cout << "Marks in Object Oriented Programming System: " << OOPS_marks << endl;
    }
};

class Medical : public Student
{
    int anatomy_marks;

public:
    void get_marks()
    {
        cout << "Enter the marks in anatomy: ";
        cin >> anatomy_marks;
    }
    void put_marks()
    {
        cout << "Marks in anatomy: " << anatomy_marks << endl;
    }
};

int main()
{

    int choice;

    while (true)
    {
        cout << "\nEnter stream:\n";
        cout << "1. Arts\n2. Engineering\n3. Medical\n4. Exit\nEnter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            int size, i;
            cout << "\nEnter number of students: ";
            cin >> size;
            Arts *a = new Arts[size];

            while (true)
            {
                cout << "\nWhat would you like to do?\n";
                cout << "1. Enter details\n2. Display details\n3. Exit\nEnter your choice: ";
                ;
                cin >> i;
                if(i==1){
                    for (int i = 0; i < size; i++)
                    {
                        cout << "\nEnter details of student " << i + 1 << "\n";
                        a[i].get_reg_no();
                        a[i].get_marks();
                    }
                }

                else if(i==2){
                    for (int i = 0; i < size; i++)
                    {
                        cout << "\nDetails of student " << i + 1 << "\n";
                        a[i].put_reg_no();
                        a[i].put_marks();
                    }
                    cout<<"\n";
                }
               else if (i==3)
               {
                    break;
               }
               else{
                cout<<"Invalid input\n";
               }
            }

            delete a;
        }
        else if (choice == 2)
        {
            int j;
            cout << "\nEnter branch:\n";
            cout << "1. Mech\n2. Comp\n3. ETC\nyour choice: ";
            cin >> j;
            if (j == 1)
            {
                int size, i;
                cout << "Enter number of students: ";
                cin >> size;
                Mech *a = new Mech[size];

                while (true)
                {
                    cout << "\nWhat would you like to do?\n";
                    cout << "1. Enter details\n2. Display details\n3. Exit\nEnter your choice: ";
                    ;
                    cin >> i;
                    if(i==1){
                    for (int i = 0; i < size; i++)
                    {
                        cout << "\nEnter details of student " << i + 1 << "\n";
                        a[i].get_reg_no();
                        a[i].get_marks();
                    }
                }

                else if(i==2){
                    for (int i = 0; i < size; i++)
                    {
                        cout << "\nDetails of student " << i + 1 << "\n";
                        a[i].put_reg_no();
                        a[i].put_marks();
                    }
                    cout<<"\n";
                }
               else if (i==3)
               {
                    break;
               }
               else{
                cout<<"\nInvalid input\n";
               }
                }

                delete a;
            }
            else if (j == 2)
            {
                int size, i;
                cout << "Enter number of students: ";
                cin >> size;
                Comp *a = new Comp[size];

                while (true)
                {
                    cout << "\nWhat would you like to do?\n";
                    cout << "1. Enter details\n2. Display details\n3. Exit\nEnter your choice: ";
                    ;
                    cin >> i;
                    if(i==1){
                    for (int i = 0; i < size; i++)
                    {
                        cout << "\nEnter details of student " << i + 1 << "\n";
                        a[i].get_reg_no();
                        a[i].get_marks();
                    }
                }

                else if(i==2){
                    for (int i = 0; i < size; i++)
                    {
                        cout << "\nDetails of student " << i + 1 << "\n";
                        a[i].put_reg_no();
                        a[i].put_marks();
                    cout<<"\n";

                    }
                }
               else if (i==3)
               {
                    break;
               }
               else{
                cout<<"\nInvalid input\n";
               }
                }

                delete a;
            }
            else if (j == 3)
            {
                int size, i;
                cout << "Enter number of students: ";
                cin >> size;
                ETC *a = new ETC[size];

                while (true)
                {
                    cout << "\nWhat would you like to do?\n";
                    cout << "1. Enter details\n2. Display details\n3. Exit\nEnter your choice: ";
                    ;
                    cin >> i;
                   if(i==1){
                    for (int i = 0; i < size; i++)
                    {
                        cout << "\nEnter details of student " << i + 1 << "\n";
                        a[i].get_reg_no();
                        a[i].get_marks();
                    }
                }

                else if(i==2){
                    for (int i = 0; i < size; i++)
                    {
                        cout << "\nDetails of student " << i + 1 << "\n";
                        a[i].put_reg_no();
                        a[i].put_marks();
                    cout<<"\n";

                    }
                }
               else if (i==3)
               {
                    break;
               }
               else{
                cout<<"\nInvalid input\n";
               }
                }

                delete a;
            }
            else
            {
                cout << "\nInvalid input\n";
            }
        }
        else if (choice == 3)
        {
            int size, i;
            cout << "Enter number of students: ";
            cin >> size;
            Medical *a = new Medical[size];

            while (true)
            {
                cout << "\nWhat would you like to do?\n";
                cout << "1. Enter details\n2. Display details\n3. Exit\nEnter your choice: ";
                ;
                cin >> i;
                
                if(i==1){
                    for (int i = 0; i < size; i++)
                    {
                        cout << "\nEnter details of student " << i + 1 << "\n";
                        a[i].get_reg_no();
                        a[i].get_marks();
                    }
                }

                else if(i==2){
                    for (int i = 0; i < size; i++)
                    {
                        cout << "\nDetails of student " << i + 1 << "\n";
                        a[i].put_reg_no();
                        a[i].put_marks();
                    cout<<"\n";

                    }
                }
               else if (i==3)
               {
                    break;
               }
               else{
                cout<<"\nInvalid input\n";
               }
            }

            delete a;
        }
        else if(choice==4){
            break;
        }
        else
        {
            cout << "\nInvalid input\n";
        }
    }

    return 0;
}