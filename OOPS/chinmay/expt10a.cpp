#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void writeToFile(const string& filename, const vector<int>& elements) {
    ofstream outFile(filename);
    for (int element : elements) {
        outFile << element << " ";
    }
    outFile.close();
}

vector<int> readFromFile(const string& filename) {
    ifstream inFile(filename);
    vector<int> elements;
    int element;
    while (inFile >> element) {
        elements.push_back(element);
    }
    inFile.close();
    return elements;
}

int main() {
    vector<int> file1Elements;
    vector<int> file2Elements;
    int n, element;

    cout << "Enter the number of elements for file1: ";
    cin >> n;
    cout << "Enter the elements for file1: ";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        file1Elements.push_back(element);
    }

    cout << "Enter the number of elements for file2: ";
    cin >> n;
    cout << "Enter the elements for file2: ";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        file2Elements.push_back(element);
    }

    writeToFile("file1.txt", file1Elements);
    writeToFile("file2.txt", file2Elements);

    vector<int> mergedElements = readFromFile("file1.txt");
    vector<int> file2ReadElements = readFromFile("file2.txt");

    mergedElements.insert(mergedElements.end(), file2ReadElements.begin(), file2ReadElements.end());
    sort(mergedElements.begin(), mergedElements.end());

    writeToFile("file3.txt", mergedElements);

    cout << "Files merged and sorted successfully into file3.txt" << endl;

    return 0;
}