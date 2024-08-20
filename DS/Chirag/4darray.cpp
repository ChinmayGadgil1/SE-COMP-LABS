#include <iostream>
using namespace std;

const int SIZE = 3;

int main() {
    int matrix[SIZE][SIZE][SIZE][SIZE];

    int val = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                for (int l = 0; l < SIZE; l++) {
                    matrix[i][j][k][l] = val++;
                    if (val > 9) val = 1; 
                }
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                for (int l = 0; l < SIZE; l++) {
                    cout << matrix[i][j][k][l] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    return 0;
}
