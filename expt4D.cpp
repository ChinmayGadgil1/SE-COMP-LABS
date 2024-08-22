#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* str;
    int length;

public:
    String() : str(nullptr), length(0) {}

    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str; // Free existing memory
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    ~String() {
        delete[] str;
    }

    String operator+(const String& other) const {
        String temp;
        temp.length = length + other.length;
        temp.str = new char[temp.length + 1];
        strcpy(temp.str, str);
        strcat(temp.str, other.str);
        return temp;
    }

    bool operator<(const String& other) const {
        return strcmp(str, other.str) < 0;
    }

    friend ostream& operator<<(ostream& out, const String& s) {
        if (s.str) {
            out << s.str;
        }
        return out;
    }

    friend istream& operator>>(istream& in, String& s) {
        char buffer[1000];
        in >> buffer;
        s.length = strlen(buffer);
        delete[] s.str; 
        s.str = new char[s.length + 1];
        strcpy(s.str, buffer);
        return in;
    }
};

int main() {
    String s1, s2, s3;

    cout << "Enter first string: ";
    cin >> s2;

    cout << "Enter second string: ";
    cin >> s3;

    s1 = s2 + s3;
    cout << "Concatenated string: ";
    cout << s1;
    cout << "\n";

    if (s2 < s3) {
        cout << "First string is smaller: ";
        cout << s2;
        cout << "\n";
    } else {
        cout << "Second string is smaller: ";
        cout << s3;
        cout << "\n";
    }

    return 0;
}
