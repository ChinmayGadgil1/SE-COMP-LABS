#include <iostream>
using namespace std;

class Vector {
private:
    int x;
    int y;

public:
    Vector(int x, int y) {
        this->x=x;
        this->y=y;
    }

    Vector operator+(const Vector& vec) {
        return Vector(x + vec.x, y + vec.y);
    }

    Vector operator-(const Vector& vec) {
        return Vector(x - vec.x, y - vec.y);
    }

    Vector operator*(int scalar) {
        return Vector(x * scalar, y * scalar);
    }

    bool operator==(const Vector& vec) {
        return (x == vec.x) && (y == vec.y);
    }

    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    int x, y, w, z;
    cout << "Enter x, y, w, z: ";
    cin >> x >> y >> w >> z;

    Vector v1(x,y);
    Vector v2(w,z);

    Vector sum = v1 + v2;
    Vector difference = v1 - v2;
    Vector scaled = v1 * 2;

    sum.print();         
    difference.print();  
    scaled.print();      

    if (v1 == v2) {
        cout << "v1 and v2 are equal" << endl;
    } else {
        cout << "v1 and v2 are not equal" << endl;
    }

    return 0;
}