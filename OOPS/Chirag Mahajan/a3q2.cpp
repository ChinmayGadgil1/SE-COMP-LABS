#include <iostream>
#include <cstring>  

using namespace std;

class String {
    char str[21];  

public:
    
    String() {
        str[0] = '\0';  
    }

    
    String(const char* s) {
        strncpy(str, s, 20);  
        str[20] = '\0';       
    }

    
    String(const String& s) {
        strncpy(str, s.str, 20);
        str[20] = '\0';
    }


    ~String() {}

    String& operator=(const String& s) {
        if (this != &s) {
            strncpy(str, s.str, 20);
            str[20] = '\0';
        }
        return *this;
    }

    friend String concat(const String& s1, const String& s2);

    void display() const {
        cout << str << endl;
    }
};

String concat(const String& s1, const String& s2) {
    String result;
    strncpy(result.str, s1.str, 20);
    strncat(result.str, s2.str, 20 - strlen(result.str));
    return result;
}

int main() {

    String s1("Hello, ");
    String s2("World!");

    cout << "String 1: ";
    s1.display();
    cout << "String 2: ";
    s2.display();

    String s3 = concat(s1, s2);
    cout << "Concatenated String: ";
    s3.display();

    String s4;
    s4 = s1;
    cout << "Assigned String: ";
    s4.display();

    return 0;
}
