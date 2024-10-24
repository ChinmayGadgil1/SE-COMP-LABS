#include <iostream>
#include <string>

using namespace std;

int main() {
 
    string str1 = "Hello";
    string str2 = "World";

  
    string str3 = str1 + " " + str2;
    cout << "Concatenated String: " << str3 << endl;

 
    if (str1 == str2) {
        cout << "Strings are equal" << endl;
    } else {
        cout << "Strings are not equal" << endl;
    }


    int found = str3.find("World");
    if (found != string::npos) {
        cout << "'World' found at: " << found << endl;
    } else {
        cout << "'World' not found" << endl;
    }

    char ch = 'o';
    found = str3.find(ch);
    if (found != string::npos) {
        cout << "Character '" << ch << "' found at: " << found << endl;
    } else {
        cout << "Character '" << ch << "' not found" << endl;
    }

    cout << "Before Swap: str1 = " << str1 << ", str2 = " << str2 << endl;
    str1.swap(str2);
    cout << "After Swap: str1 = " << str1 << ", str2 = " << str2 << endl;

    return 0;
}