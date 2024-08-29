# include<iostream>
#include<string>
using namespace std;

class Account{
    protected:
    string name;
    long long acc_num;
    string type;
    double amount;
    public:
        Account(string n,long long acc,string t,double a){
            name=n;
            acc_num=acc;
            type=t;
            amount=a;
        }
        void deposit(double a){
            amount+=a;
        }    

       

        void display(){
            cout<<amount<<endl;
        }
        
};

class savings:public Account{
    static double interest;
    public:
        savings(string n,long long acc,double amt):Account(n,acc,"SAVINGS",amt){}

        void computeInterest(int years){
            for(int i=0;i<years;i++){
                amount+=amount*interest;
            }
        }
        void withdraw(double amt){
            if(amount-amt<0){
                cout<<"\nInsufficient balance\n";
                return;
            }
            amount-=amt;
        }
};
double savings::interest=0.04;

class cur_acc:public Account{
    static int minbal;
    public:
    cur_acc(string n,long long acc,double amt):Account(n,acc,"CURRENT",amt){}
    void withdraw(double amt){
            if(amount-amt<minbal){
                amt+=amt*0.1;
            }
            amount-=amt;
        }
};
int cur_acc::minbal=2000;

int main(){
    string name;
    long long acc_num;
    double amount;
    int choice, years,type;
    double deposit_amt, withdraw_amt;

    cout << "Enter account holder name: ";
    getline(cin, name);
    cout << "Enter account number: ";
    cin >> acc_num;
    cout << "Enter initial amount: ";
    cin >> amount;
    label:
    cout<<"Enter type of account:\n";
    cout<<"1.Savings\n";
    cout<<"2.Current\n";
    cout<<" -> ";
    cin>>type;
    if(type==1){
        savings s(name, acc_num, amount);
        do {
        cout << "\n----- Menu -----\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Compute Interest\n";
        cout << "4. Display Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> deposit_amt;
                s.deposit(deposit_amt);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> withdraw_amt;
                s.withdraw(withdraw_amt);
                break;
            case 3:
                cout << "Enter number of years: ";
                cin >> years;
                s.computeInterest(years);
                break;
            case 4:
                cout << "Account balance: ";
                s.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);
    }
    else if (type==2)
    {
    cur_acc c(name, acc_num, amount);
        do {
        cout << "\n----- Menu -----\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> deposit_amt;
                c.deposit(deposit_amt);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> withdraw_amt;
                c.withdraw(withdraw_amt);
                break;
            case 3:
                cout << "Account balance: ";
                c.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }while(choice!=4);
    }
    else{
        goto label;
    }
    

    

    return 0;
}
