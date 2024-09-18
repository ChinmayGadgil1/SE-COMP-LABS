#include <iostream>
using namespace std;

class Account {
protected:
    string customer_name;
    int account_number;
    string account_type;
    double balance;

public:
    void init_account(string name, int number, string type) {
        customer_name = name;
        account_number = number;
        account_type = type;
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void display_balance() const {
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interest_rate;

public:
    void init_savings(string name, int number, string type, double rate) {
        init_account(name, number, type);
        interest_rate = rate;
    }

    void compute_interest() {
        double interest = balance * interest_rate;
        balance += interest;
        cout << "Interest added: " << interest << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful: " << amount << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
};

class CurrentAccount : public Account {
private:
    double minimum_balance;
    double service_charge;

public:
    void init_current(string name, int number, string type, double min_bal, double charge) {
        init_account(name, number, type);
        minimum_balance = min_bal;
        service_charge = charge;
    }

    void check_minimum_balance() {
        if (balance < minimum_balance) {
            balance -= service_charge;
            cout << "Balance below minimum. Service charge of " << service_charge << " applied." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful: " << amount << endl;
            check_minimum_balance();
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
};

int main() {

    SavingsAccount saveAcc;
    saveAcc.init_savings("John", 12345, "Savings", 0.04);
    saveAcc.deposit(5000);
    saveAcc.display_balance();
    saveAcc.compute_interest();
    saveAcc.display_balance();
    saveAcc.withdraw(1000);
    saveAcc.display_balance();
    cout << endl;

    CurrentAccount currAcc;
    currAcc.init_current("Jane", 67890, "Current", 1000.0, 50.0);
    currAcc.deposit(2000);
    currAcc.display_balance();
    currAcc.withdraw(1200);
    currAcc.display_balance();

    return 0;
}
