#include <iostream>
using namespace std;

void calculateSimpleInterest(double &principal, double rate, int time, double &interest) {
    interest = (principal * rate * time) / 100;
}

int main() {
    double principal;
    double rate;
    int time;
    double interest = 0.0;

    cout << "Enter the principal amount: ";
    cin >> principal;
    cout << "Enter the interest rate (in %): ";
    cin >> rate;
    cout << "Enter the time period (in years): ";
    cin >> time;

    calculateSimpleInterest(principal, rate, time, interest);

    cout << "Calculated Simple Interest: " << interest << endl;

    return 0;
}
