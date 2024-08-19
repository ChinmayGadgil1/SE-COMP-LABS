#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double breadth;

public:
   
    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    double area() {
        return length * breadth;
    }
};

int main() {
    double length, breadth;

    
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the breadth of the rectangle: ";
    cin >> breadth;

   
    Rectangle rect(length, breadth);

    
    cout << "Area of the rectangle: " << rect.area() << endl;

    return 0;
}
