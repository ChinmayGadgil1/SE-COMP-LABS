#include <iostream>
using namespace std;
class Rectangle {
private:
int length;
int width;
public:
Rectangle(int l, int w) {
length = l;
width = w;
cout << "Rectangle created with length " << length << " and width " << width
<< endl;
}
~Rectangle() {
cout << "Rectangle destroyed with length " << length << " and width " << width
<< endl;
}
int area() {
return length * width;
}
void display() {
cout << "Length: " << length << ", Width: " << width << endl;
}
};
int main() {
Rectangle rect1(10, 5);
rect1.display();
cout << "Area of rect1: " << rect1.area() <<
endl;
return 0;
}
