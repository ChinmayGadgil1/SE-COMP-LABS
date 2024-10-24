#include <iostream>
using namespace std;

void divide(int a, int b) {
    try {
        if (b == 0) {
            throw runtime_error("Division by zero error");
        }
        cout << "Result: " << a / b << endl;
    } catch (const runtime_error& e) {
        cout << "Caught an exception: " << e.what() << endl;
        throw;
    }
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    try {
        divide(x, y);
    } catch (const runtime_error& e) {
        cout << "Exception rethrown and caught in main: " << e.what() << endl;
    }

    return 0;
}