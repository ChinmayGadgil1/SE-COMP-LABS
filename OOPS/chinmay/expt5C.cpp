#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    string brand;

    Vehicle(string b) : brand(b) {
        cout << "Vehicle constructor called. Brand: " << brand << endl;
    }

    ~Vehicle() {
        cout << "Vehicle destructor called." << endl;
    }
};

class FourWheeler : public Vehicle {
public:
    int numWheels;

    FourWheeler(string b, int nw) : Vehicle(b), numWheels(nw) {
        cout << "FourWheeler constructor called. Number of wheels: " << numWheels << endl;
    }


    ~FourWheeler() {
        cout << "FourWheeler destructor called." << endl;
    }
};

class Sedan : public FourWheeler {
public:
    string model;

    Sedan(string b, int nw, string m) : FourWheeler(b, nw), model(m) {
        cout << "Sedan constructor called. Model: " << model << endl;
    }

    ~Sedan() {
        cout << "Sedan destructor called." << endl;
    }
};

int main() {
    string brand, model;
    int numWheels;

    cout << "Enter the brand of the vehicle: ";
    cin >> brand;

    cout << "Enter the number of wheels: ";
    cin >> numWheels;

    cout << "Enter the model of the sedan: ";
    cin >> model;

    cout << "Creating a Sedan object." << endl;
    Sedan myCar(brand, numWheels, model);  

    cout << "Exiting the program." << endl;
    return 0;
}
