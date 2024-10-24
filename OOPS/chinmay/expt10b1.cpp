#include <iostream>
#include <string>
#include <iterator>

using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str); 

    for (string::iterator it = str.begin(); it != str.end(); ++it) {
        cout << *it;
    }
    cout << endl;
    return 0;
}