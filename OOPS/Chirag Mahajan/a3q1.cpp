#include <iostream>
#include <cmath>
using namespace std;

class Rectangle;

class Polar {
    double r, a;  
public:
    Polar(double radius = 0, double angle = 0) {
        r = radius;
        a = angle;
    }
    
    double getRadius() { 
        return r; 
        }
    double getAngle() { 
        return a; 
        }

    Polar(Rectangle rect);

    void display() {
        cout << "Polar Coordinates: (" << r << ", " << a << " radians)" << endl;
    }
};

class Rectangle {
    double x, y;  
public:
   Rectangle(double x_coord = 0, double y_coord = 0) {
        x = x_coord;
        y = y_coord;
    }

    double getX() { 
        return x; 
        }
    double getY() { 
        return y; 
        }

    Rectangle(Polar polar) {
        x = polar.getRadius() * cos(polar.getAngle());
        y = polar.getRadius() * sin(polar.getAngle());
    }

    void display() {
        cout << "Rectangle Coordinates: (" << x << ", " << y << ")" << endl;
    }
};

Polar::Polar(Rectangle rect) {
    r = sqrt(rect.getX() * rect.getX() + rect.getY() * rect.getY());
    a = atan2(rect.getY(), rect.getX()); 
}

int main() {

    Polar polar(5.0, 0.927);  
    Rectangle rect_from_polar = polar;
    rect_from_polar.display();

   
    Rectangle rect(3.0, 4.0); 
    Polar polar_from_rect = rect;
    polar_from_rect.display();

    return 0;
}
