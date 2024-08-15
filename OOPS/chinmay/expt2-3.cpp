#include <iostream>
#include <cmath>
using namespace std;

double volume(double side) {
    return side * side * side;
}

double volume(double length, double width, double height) {
    return length * width * height;
}

double volume(double radius, double height) {

    return 3.14 * radius * radius * height;
}

int main() {
    double side, length, width, height, radius;

    cout << "Enter the side length of the cube: ";
    cin >> side;
    cout << "Volume of the cube: " << volume(side) << endl;

    cout << "Enter the length, width, and height of the cuboid: ";
    cin >> length >> width >> height;
    cout << "Volume of the cuboid: " << volume(length, width, height) << endl;

    cout << "Enter the radius and height of the cylinder: ";
    cin >> radius >> height;
    cout << "Volume of the cylinder: " << volume(radius, height) << endl;

    return 0;
}
