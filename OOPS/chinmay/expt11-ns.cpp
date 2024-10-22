#include <iostream>
#include <vector>
#include <string>
// #include <algorithm>
using namespace std;

int main() {
    vector<string> lines;
    string line;
    int maxLength = 0;

    cout << "Enter lines of text (type 'END' to finish):" << endl;

    while (getline(cin, line) && line != "END") {
        lines.push_back(line);
        if (line.length() > maxLength) {
            maxLength = line.length();
        }
    }

    cout << "\nRight-justified text:" << endl;

    for (const auto& l : lines) {
        cout << string(maxLength - l.length(), ' ') << l << endl;
    }

    return 0;
}