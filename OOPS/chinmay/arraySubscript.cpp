#include <bits/stdc++.h>
using namespace std;

class A
{
    int *arr;
    int n;

public:
    A()
    {
        arr = NULL;
        n = 0;
    }
    A(int a)
    {
        arr = new int[a];
        n = a;
    }
    A(A &a)
    {
        arr = a.arr;
        n = a.n;
    }

    int operator[](int index)
    {
        return arr[index];
    }
    void set()
    {
        cout << "Enter " << n << " elements:";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
};

int main()
{

    A a(4);
    a.set();

    cout << a[3];

    return 0;
}