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
    vector<int> file1Elements = {5, 2, 9, 1, 6};
    vector<int> file2Elements = {8, 3, 7};

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