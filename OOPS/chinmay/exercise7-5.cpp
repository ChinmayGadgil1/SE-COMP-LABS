#include <iostream>
#include <cmath>
using namespace std;

class polar {
private:
    double radius;
    double angle;

public:
    polar(double r = 0, double a = 0) : radius(r), angle(a) {}

    void setPolar(double r, double a) {
        radius = r;
        angle = a;
    }

    void displayPolar() {
        cout << "Polar coordinates: (" << radius << ", " << angle << " degrees)" << endl;
    }

    double getRadius() {
        return radius;
    }

    double getAngle() {
        return angle;
    }
};

class rectangular {
private:
    double x;
    double y;

public:
    rectangular(double xVal = 0, double yVal = 0) : x(xVal), y(yVal) {}

    void setRectangular(double xVal, double yVal) {
        x = xVal;
        y = yVal;
    }

    void displayRectangular() {
        cout << "Rectangular coordinates: (" << x << ", " << y << ")" << endl;
    }

    double getX() {
        return x;
    }

    double getY() {
        return y;
    }
};

int main() {
    int choice;
    polar p;
    rectangular r;

    do {
        cout << "Menu:" << endl;
        cout << "1. Convert Polar to Rectangular" << endl;
        cout << "2. Convert Rectangular to Polar" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double radius, angle;
                cout << "Enter polar radius: ";
                cin >> radius;
                cout << "Enter polar angle (in degrees): ";
                cin >> angle;

                p.setPolar(radius, angle);
                r.setRectangular(radius * cos(angle * M_PI / 180), radius * sin(angle * M_PI / 180));

                p.displayPolar();
                r.displayRectangular();
                break;
            }
            case 2: {
                double x, y;
                cout << "Enter rectangular x-coordinate: ";
                cin >> x;
                cout << "Enter rectangular y-coordinate: ";
                cin >> y;

                r.setRectangular(x, y);
                p.setPolar(sqrt(x * x + y * y), atan(x/y) * 180 / M_PI);

                r.displayRectangular();
                p.displayPolar();
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 3);

    return 0;
}