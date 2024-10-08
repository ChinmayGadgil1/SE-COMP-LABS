#include <iostream>
#include <vector>
using namespace std;

template <class T>
class GenericVector {
private:
    vector<T> vec;

public:
    void createVector(const vector<T>& elements) {
        vec = elements;
    }
    void modifyElement(size_t index, const T& value) {
        if (index < vec.size()) {
            vec[index] = value;
        } else {
            cerr << "Index out of bounds" << endl;
        }
    }

    
    void displayVector() const {
        for (const auto& element : vec) {
            cout << element << " ";
        }
        cout << endl;
    }
};

int main() {
    GenericVector<int> intVector;
    intVector.createVector({1, 2, 3, 4, 5});
    intVector.displayVector();

    intVector.modifyElement(2, 10);
    intVector.displayVector();

    GenericVector<string> stringVector;
    stringVector.createVector({"Goa", "Engineering", "College"});
    stringVector.displayVector();

    stringVector.modifyElement(0, "Bomabay");
    stringVector.displayVector();

    return 0;
}