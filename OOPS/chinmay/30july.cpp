#include <iostream>
using namespace std;

template <class T1>
class Pair
{
    T1 first;
    T1 second;

public:
    void input(T1 a, T1 b)
    {
        first = a;
        second = b;
    }

    void display()
    {
        cout << "\nfirst=" << first << "  " << "second=" << second << "\n";
    }

    
    friend void swapValues(Pair<T1> &p)
    {
        T1 tmp = p.first;
        p.first = p.second;
        p.second = tmp;
    }
};

int main()
{
    cout << "\nWhat type of Pair do you need?\n";
    cout << "1.Integer\n2.Character\n3.Float\n";
    int choice = 0;
    cout << "Enter your choice: ";
    cin >> choice;
    int a, b;
    char e, f;
    float c, d;

    switch (choice)
    {
    case 1:
    {
        Pair<int> p1;
        cout << "Enter 2 numbers: ";
        cin >> a >> b;
        p1.input(a, b);
        cout << "\nBefore Swapping:";
        p1.display();
        cout << "\nAfter Swapping:";
        swapValues(p1);
        p1.display();
        break;
    }
    case 2:
    {
        Pair<char> p2;
        cout << "Enter 2 characters: ";
        cin >> e >> f;
        p2.input(e, f);
        cout << "\nBefore Swapping:";
        p2.display();
        cout << "\nAfter Swapping:";
        swapValues(p2);
        p2.display();
        break;
    }
    case 3:
    {
        Pair<float> p3;
        cout << "Enter 2 floats: ";
        cin >> c >> d;
        p3.input(c, d);
        cout << "\nBefore Swapping:";
        p3.display();
        cout << "\nAfter Swapping:";
        swapValues(p3);
        p3.display();
        break;
    }
    default:
        cout << "Invalid choice!\n";
        break;
    }

    cout<<endl;

    return 0;
}
