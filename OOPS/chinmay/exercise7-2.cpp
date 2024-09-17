#include <iostream>
#include <cmath>
using namespace std;

class Polar {
private:
    double radius;
    double angle; 

public:
    Polar(double r = 0, double a = 0) : radius(r), angle(a) {}

    double getRadius() const {
        return radius;
    }

    double getAngle() const {
        return angle;
    }

    Polar operator+(const Polar& other) const {
   
        double x1 = radius * cos(angle);
        double y1 = radius * sin(angle);
        double x2 = other.radius * cos(other.angle);
        double y2 = other.radius * sin(other.angle);

      
        double x = x1 + x2;
        double y = y1 + y2;
        double r = sqrt(x * x + y * y);
        double a = atan2(y, x); 

        return Polar(r, a);
    }
};

int main() {
    int choice;
    double radius, angle;

    Polar p1, p2, result;

    do {
        cout << "Menu:" << endl;
        cout << "1. Set polar coordinates for p1" << endl;
        cout << "2. Set polar coordinates for p2" << endl;
        cout << "3. Add p1 and p2" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter radius for p1: ";
                cin >> radius;
                cout << "Enter angle (in degrees) for p1: ";
                cin >> angle;
                p1 = Polar(radius, angle * M_PI / 180.0); 
                break;
            case 2:
                cout << "Enter radius for p2: ";
                cin >> radius;
                cout << "Enter angle (in degrees) for p2: ";
                cin >> angle;
                p2 = Polar(radius, angle * M_PI / 180.0); 
                break;
            case 3:
                result = p1 + p2;
                cout << "Resultant polar coordinates: (" << result.getRadius() << ", " << result.getAngle() * 180.0 / M_PI << " degrees)" << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
