#include <iostream>
using namespace std;

class Complex {
    int a, b;

public:
    Complex() {
        a = 0;
        b = 0;
    }

    Complex(int real, int imag) { 
        a = real;
        b = imag;
    }

    Complex operator+(Complex& other) { 
        return Complex(a + other.a, b + other.b);
    }

    Complex operator*(Complex& other) { //(a + bi)*(c + di) = (ac - bd) + (ad + bc)i
        int real = (a * other.a) - (b * other.b);
        int imag = (a * other.b) + (b * other.a);
        return Complex(real, imag);
    }

    friend ostream& operator<<(ostream& os, Complex& c) {
        os << c.a << " + " << c.b << "i";
        return os;
    }
};

int main() {
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = c1 + c2;
    Complex c4 = c1 * c2;

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c3: " << c3 << endl;
    cout << "c4: " << c4 << endl;

    return 0;
}