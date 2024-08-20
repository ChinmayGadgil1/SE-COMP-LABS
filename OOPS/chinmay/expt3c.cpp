#include <iostream>
using namespace std;

class IntArray {
private:
    int* arr;
    int size;

public:
 
    IntArray(int s) {
        size = s;
        arr = new int[size];
        cout << "Array of size " << size << " created." << endl;
    }

    
    ~IntArray() {
        delete[] arr;
        cout << "Array of size " << size << " destroyed and memory freed." << endl;
    }


    void fillArray() {
        cout << "Enter " << size << " integers:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }
    }

   
    void printArray() const {
        cout << "Array contents: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;

 
    cout << "Enter the size of the array: ";
    cin >> n;

 
    IntArray array(n);
    
    array.fillArray();
    array.printArray();

    

    return 0;
}
