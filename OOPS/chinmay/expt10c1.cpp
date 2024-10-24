#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string input = "123 456 789";
    istringstream iss(input);
    int a, b, c;

    iss >> a >> b >> c;

    cout << "The extracted integers are: " << a << ", " << b << ", " << c << endl;

    ostringstream oss;
    oss << a << " " << b << " " << c;
    string output = oss.str();

    cout << "The output string is: " << output << endl;

    return 0;
}