#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input;
    string line;
    int numLines = 0, numWords = 0, numChars = 0;

    cout << "Enter text (end input with an empty line):" << endl;

    while (getline(cin, line) && !line.empty()) {
        numLines++;
        numChars += line.length();
        istringstream iss(line);
        string word;
        while (iss >> word) {
            numWords++;
        }
    }

    cout << left << setw(15) << "Lines" 
              << right << setw(10) << numLines << endl;
    cout << left << setw(15) << "Words" 
              << right << setw(10) << numWords << endl;
    cout << left << setw(15) << "Characters" 
              << right << setw(10) << numChars << endl;

    return 0;
}