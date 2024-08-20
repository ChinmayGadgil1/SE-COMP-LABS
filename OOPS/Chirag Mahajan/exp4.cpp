#include <iostream>
using namespace std;

class Counter {
private:
    int count;
public:
    // Constructor to initialize count
    Counter() : count(0) {}

    // Overload prefix increment operator
    Counter& operator++() {
        ++count;
        return *this;
    }

    // Overload postfix increment operator
    Counter operator++(int) {
        Counter temp = *this;
        count++;
        return temp;
    }

    // Overload prefix decrement operator
    Counter& operator--() {
        --count;
        return *this;
    }

    // Overload postfix decrement operator
    Counter operator--(int) {
        Counter temp = *this;
        count--;
        return temp;
    }

    // Method to display the count
    void display() const {
        cout << "Count: " << count << endl;
    }
};

int main() {
    Counter c;

    cout << "Initial count: ";
    c.display();

    ++c;
    cout << "After prefix increment: ";
    c.display();

    c++;
    cout << "After postfix increment: ";
    c.display();

    --c;
    cout << "After prefix decrement: ";
    c.display();

    c--;
    cout << "After postfix decrement: ";
    c.display();

    return 0;
}