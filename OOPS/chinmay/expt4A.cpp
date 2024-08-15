#include <iostream>

using namespace std;

class Counter {
private:
    int value;
public:
    Counter(){
        value = 0; 
    }

    Counter(int v) {
        value = v;
    }

    void operator++() {
        ++value;
    }

    void operator ++(int) {
        value++;
    }

    void operator--() {
        --value;
    }

    void operator--(int) {  
        value--;
    }

    void display() const {
        cout << "Counter value: " << value << endl;
    }
};

int main() {
    Counter c(10);

    cout << "Initial value: ";
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