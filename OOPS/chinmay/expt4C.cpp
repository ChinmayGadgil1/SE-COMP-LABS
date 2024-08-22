#include <iostream>

using namespace std;

class MyClass {
private:
    int value;

public:
    MyClass()  {
        value=0;
    }
    MyClass(int val) : value(val) {}

    friend istream& operator>>(istream& in, MyClass& obj) {
        cout << "Enter value: ";
        in >> obj.value;
        return in;
    }

    friend ostream& operator<<(ostream& out, const MyClass& obj) {
        out << "Value: " << obj.value;
        return out;
    }
};

int main() {
    MyClass obj1, obj2;

    cin >> obj1;
    cin >> obj2;

    cout << obj1 << endl;
    cout << obj2 << endl;

    return 0;
}