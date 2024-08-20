#include <iostream>
#include <cmath>
using namespace std;

bool checkPrime(int num) {
    if (num < 2) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool checkOdd(int num) {
    return num % 2 != 0;
}

int main() {
    cout << "Enter a number: ";
    int number;
    cin >> number;

    if (checkOdd(number) && checkPrime(number)) {
        cout << "The entered number is both odd and prime." << endl;
    } else if (checkOdd(number)) {
        cout << "The entered number is odd but not prime." << endl;
    } else if (checkPrime(number)) {
        cout << "The entered number is prime but not odd." << endl;
    } else {
        cout << "The entered number is neither odd nor prime." << endl;
    }

    return 0;
}
