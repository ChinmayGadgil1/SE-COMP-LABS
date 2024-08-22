#include <iostream>

using namespace std;

class Operator {
private:
    int value;

public:
    Operator(int val) : value(val) {}

    Operator operator+(const Operator& other) const {
        return Operator(value + other.value);
    }

    Operator operator*(const Operator& other) const {
        return Operator(value * other.value);
    }

    Operator operator-(const int& num) const {
        return Operator(value - num);
    }

    void display() const {
        cout << "Value: " << value << endl;
    }

    int getValue() const {
        return value;
    }
};

Operator operator+(int num, const Operator& obj) {
    return Operator(num + obj.getValue());
}

int main() {
    Operator x(10);
    Operator y(20);

    x = 5 + y;
    x.display();

    x = x * y;
    x.display();

    x = y - 5;
    x.display();

    return 0;
}