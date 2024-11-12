#include <iostream>
#include <vector>

using namespace std;

class Vector {
private:
    vector<int> data;

public:
 
    Vector(int size) : data(size) {}

 
    int& operator[](int index) {
        return data[index];
    }


    Vector operator*(int scalar) const {
        Vector result(data.size());
        for (int i = 0; i < data.size(); i++) {
            result[i] = data[i] * scalar;
        }
        return result;
    }


    Vector operator+(const Vector& other) const {
        if (data.size() != other.data.size()) {
            throw runtime_error("Vectors must be of the same size for addition");
        }
        Vector result(data.size());
        for (int i = 0; i < data.size(); i++) {
            result[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Method to print the vector elements
    void print() const {
        for (int i = 0; i < data.size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the vector: ";
    cin >> n;

    Vector vec(n);

    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int choice;
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Multiply vector by scalar" << endl;
        cout << "2. Add two vectors" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int scalar;
                cout << "Enter the scalar value: ";
                cin >> scalar;

                Vector result = vec * scalar;

                cout << "Updated vector after scalar multiplication: ";
                result.print();
                break;
            }
            case 2: {
                Vector vec2(n);

                cout << "Enter the elements of the second vector: ";
                for (int i = 0; i < n; i++) {
                    cin >> vec2[i];
                }
                    Vector result = vec + vec2;
                    cout << "Result of addition of two vectors: ";
                    result.print();
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
