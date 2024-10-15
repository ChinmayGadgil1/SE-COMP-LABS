#include <iostream>
using namespace std;

template <class T>
void swapElements(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
   cout << "Before swap: x = " << x << ", y = " << y <<endl;
    swapElements(x, y);
   cout << "After swap: x = " << x << ", y = " << y <<endl;

    double a = 1.1, b = 2.2;
   cout << "Before swap: a = " << a << ", b = " << b <<endl;
    swapElements(a, b);
   cout << "After swap: a = " << a << ", b = " << b <<endl;

    return 0;
}