#include <iostream>
using namespace std;

class Box {
private:
    double length;
    double width;
    double height;

public:
    Box(double l, double w, double h){
        length=l;
        width=w;
        height=h;
    }

    inline double volume() const {
        return length * width * height;
    }

    friend void displayDimensions(const Box& b);
};

void displayDimensions(const Box& b) {
    cout << "Length: " << b.length << endl;
    cout << "Width: " << b.width << endl;
    cout << "Height: " << b.height << endl;
}

int main() {
    double length, width, height;

    cout << "Enter the length of the box: ";
    cin >> length;
    cout << "Enter the width of the box: ";
    cin >> width;
    cout << "Enter the height of the box: ";
    cin >> height;

    Box box(length, width, height);

    cout << "Volume of the box: " << box.volume() << endl;
    displayDimensions(box);

    return 0;
}
