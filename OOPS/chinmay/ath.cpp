#include <iostream>
#include <cstring>

using namespace std;

// Function to replace a pattern in a string
void replacePattern(string &s, const string &pattern, const string &replacement) {
    int pos = s.find(pattern);
    while (pos != -1) {
        s.replace(pos, pattern.length(), replacement);
        pos = s.find(pattern, pos + replacement.length());
    }
}

// Function to validate an email address
bool isValidEmail(const string &email) {
    int atPos = email.find('@');
    int dotPos = email.find('.');
    return (atPos != -1 && dotPos != -1 && atPos < dotPos);
}

// Function to validate a phone number
bool isValidPhoneNumber(const string &phone) {
    if (phone.length() != 10) {
        return false;
    }
    for (int i = 0; i < phone.length(); i++) {
        if (!isdigit(phone[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Replace pattern in string\n";
        cout << "2. Validate email address\n";
        cout << "3. Validate phone number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string s, pattern, replacement;
                cout << "Enter a string: ";
                cin.ignore(); // To ignore the newline character left by previous input
                getline(cin, s);
                cout << "Enter the pattern you want to replace: ";
                cin >> pattern;
                cout << "Enter the replacement string: ";
                cin >> replacement;
                replacePattern(s, pattern, replacement);
                cout << "Modified string: " << s << endl;
                break;
            }
            case 2: {
                string email;
                cout << "Enter an email address to validate: ";
                cin >> email;
                if (isValidEmail(email)) {
                    cout << "Valid email address." << endl;
                } else {
                    cout << "Invalid email address." << endl;
                }
                break;
            }
            case 3: {
                string phone;
                cout << "Enter a phone number to validate: ";
                cin >> phone;
                if (isValidPhoneNumber(phone)) {
                    cout << "Valid phone number." << endl;
                } else {
                    cout << "Invalid phone number." << endl;
                }
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
