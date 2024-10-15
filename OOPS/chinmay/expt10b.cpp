#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
using namespace std;

class TelephoneDirectory {
private:
    unordered_map<string, string> directory;
    const string filename = "expt8.txt";

    void saveToFile() {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& entry : directory) {
                file << entry.first << ": " << entry.second << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void loadFromFile() {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                size_t pos = line.find(": ");
                if (pos != string::npos) {
                    string name = line.substr(0, pos);
                    string number = line.substr(pos + 2);
                    directory[name] = number;
                }
            }
            file.close();
        } else {
            cout << "Unable to open file for reading." << endl;
        }
    }

public:
    TelephoneDirectory() {
        loadFromFile();
    }

    ~TelephoneDirectory() {
        saveToFile();
    }

    void addEntry(const string& name, const string& number) {
        directory[name] = number;
        cout << "Entry added successfully." << endl;
        saveToFile();
    }

    void updateEntry(const string& name, const string& number) {
        if (directory.find(name) != directory.end()) {
            directory[name] = number;
            cout << "Entry updated successfully." << endl;
            saveToFile();
        } else {
            cout << "Name not found in the directory." << endl;
        }
    }

    void searchEntry(const string& name) {
        if (directory.find(name) != directory.end()) {
            cout << "Name: " << name << ", Number: " << directory[name] << endl;
        } else {
            cout << "Name not found in the directory." << endl;
        }
    }
};

int main() {
    TelephoneDirectory td;
    int choice;
    string name, number;

    while (true) {
        cout << "\nTelephone Directory Menu:\n";
        cout << "1. Add Entry\n";
        cout << "2. Update Entry\n";
        cout << "3. Search Entry\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter number: ";
                getline(cin, number);
                td.addEntry(name, number);
                break;
            case 2:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter new number: ";
                getline(cin, number);
                td.updateEntry(name, number);
                break;
            case 3:
                cout << "Enter name: ";
                getline(cin, name);
                td.searchEntry(name);
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}