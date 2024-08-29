#include <iostream>
#include <cmath>
using namespace std;

class Bank {
protected:
    int acc_no;
    double balance;
public:
    void setAccNo(int acc) { acc_no = acc; }
    int getAccNo() { return acc_no; }
    void setBalance(double bal) { balance = bal; }
    double getBalance() { return balance; }
};

class SavingsAccount : public Bank {
public:
    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance" << endl;
        }
    }

    void calculateCompoundInterest(int time) {
        double rate = 5.0; // Fixed interest rate of 5%
        balance = balance * pow((1 + rate / 100), time);
    }
};

class CurrentAccount : public Bank {
public:
    void deposit(double amount) {
        balance += amount;
        checkMinimumBalance();
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            checkMinimumBalance();
        } else {
            cout << "Insufficient balance" << endl;
        }
    }

    void checkMinimumBalance() {
        if (balance < 5000) {
            balance -= 1000;
            cout << "Service charge of Rs.1000 imposed due to low balance" << endl;
        }
    }

    void issueCheckBook() {
        cout << "Check book issued" << endl;
    }
};

int main() {
    int choice;
    while (true) {
        cout << "Select Account Type: 1. Savings 2. Current 3. Exit: ";
        cin >> choice;

        if (choice == 1) {
            SavingsAccount savings;
            int accNo;
            double balance, amount;
            int action, time;

            cout << "Enter Account Number: ";
            cin >> accNo;
            savings.setAccNo(accNo);

            cout << "Enter Initial Balance: ";
            cin >> balance;
            savings.setBalance(balance);

            while (true) {
                cout << "Select Action: 1. Deposit 2. Withdraw 3. Calculate Interest 4. Exit: ";
                cin >> action;

                if (action == 1) {
                    cout << "Enter Deposit Amount: ";
                    cin >> amount;
                    savings.deposit(amount);
                } else if (action == 2) {
                    cout << "Enter Withdrawal Amount: ";
                    cin >> amount;
                    savings.withdraw(amount);
                } else if (action == 3) {
                    cout << "Enter Time Period (in years): ";
                    cin >> time;
                    savings.calculateCompoundInterest(time);
                } else if (action == 4) {
                    break;
                } else {
                    cout << "Invalid action!" << endl;
                }

                cout << "Savings Account: AccNo = " << savings.getAccNo() << ", Balance = " << savings.getBalance() << endl;
            }
        } else if (choice == 2) {
            CurrentAccount current;
            int accNo;
            double balance, amount;
            int action;

            cout << "Enter Account Number: ";
            cin >> accNo;
            current.setAccNo(accNo);

            cout << "Enter Initial Balance: ";
            cin >> balance;
            current.setBalance(balance);

            while (true) {
                cout << "Select Action: 1. Deposit 2. Withdraw 3. Issue Check Book 4. Exit: ";
                cin >> action;

                if (action == 1) {
                    cout << "Enter Deposit Amount: ";
                    cin >> amount;
                    current.deposit(amount);
                } else if (action == 2) {
                    cout << "Enter Withdrawal Amount: ";
                    cin >> amount;
                    current.withdraw(amount);
                } else if (action == 3) {
                    current.issueCheckBook();
                } else if (action == 4) {
                    break;
                } else {
                    cout << "Invalid action!" << endl;
                }

                cout << "Current Account: AccNo = " << current.getAccNo() << ", Balance = " << current.getBalance() << endl;
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}